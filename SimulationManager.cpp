#include "SimulationManager.h"
#include "PassengerState.h"

#include <QEventLoop>

SimulationManager::SimulationManager(
    std::vector<Elevator*> elevators,
    std::vector<Passenger*> passengers,
    std::vector<Floor*> floors,
    std::vector<ElevatorSetting*> elevatorSettings,
    std::vector<PassengerSetting*> passengerSettings,
    BuildingSetting *buildingSetting,
    ElevatorControl *ecs
) {

    for(auto &el : elevators) this->elevators.push_back(el);
    for(auto &pass : passengers) this->passengers.push_back(pass);
    for(auto &floor : floors) this->floors.push_back(floor);
    for(auto &el : elevatorSettings) this->elevatorSettings.push_back(el);
    for(auto &pass : passengerSettings) this->passengerSettings.push_back(pass);

    this->buildingSetting = buildingSetting;
    this->ecs = ecs;
    this->simUpdater = new SimulationUpdater();
    this->timer = new QTimer();
}

SimulationManager::~SimulationManager() {
    delete simUpdater;
    delete timer;
}

bool SimulationManager::runTurn(int turn){

    processElevatorSetting(turn);
    processPassengerSetting(turn);
    processBuildingSetting(turn); // building setting may clear passenger request
    updateUI();

    // move elevators & update passengers
    moveElevators();
    updatePassengers();
    updateUI();

    bool cont = shouldContinue(turn);
    if(!cont) return cont;

    // start elevators for the next turn
    startElevators();

    return shouldContinue(turn);
}

bool SimulationManager::shouldContinue(int turn) { // checks if the simulation should continue
    
    for(auto &pSetting : passengerSettings) { // has passenger setting to process 
        if(pSetting->getTimeFloorPressed() >= turn ||
            pSetting->getTimeHelpPressed() >= turn ||
            pSetting->getTimeOpenDoorPressed() >= turn ||
            pSetting->getTimeCloseDoorPressed() >= turn
        ) return true;
    }
    
    for(auto &eSetting : elevatorSettings) { // has elevator setting to process
        if(eSetting->getOverloadedTime() >= turn || eSetting->getObstacleTime() >= turn) return true;
    }

    // has building setting to process
    if((buildingSetting->getFire() && buildingSetting->getFireTime() >= turn) || 
        (buildingSetting->getPowerOutage() && buildingSetting->getPowerOutageTime() >= turn)) return true;

    // elevator still have tasks
    if(ecs->hasRequests()) return true;

    return false;
}

// UI 
void SimulationManager::updateUI() {
    simUpdater->updateUI(elevators, passengers, floors);

    // pause for a couple seconds
    QEventLoop loop;
    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
}

// Elevators
void SimulationManager::moveElevators() {
    ecs->moveElevators();
}

void SimulationManager::startElevators() {
    ecs->startElevators();
}

// Settings
bool SimulationManager::hasBuildingSetting(int turn){
    return ( 
        (buildingSetting->getFireTime() <= turn && buildingSetting->getFire()) ||
        (buildingSetting->getPowerOutageTime() <= turn && buildingSetting->getPowerOutage())
    );
}

bool SimulationManager::hasElevatorSetting(int turn) {
    for(auto &setting : elevatorSettings){
        if((setting->getOverloaded() && setting->getOverloadedTime() <= turn)) return true;
        if((setting->getObstacle() && setting->getObstacleTime() <= turn)) return true;
    }
    return false;
}

void SimulationManager::processElevatorSetting(int turn) {
    for(auto &setting : elevatorSettings) {

        if((setting->getOverloaded() && setting->getOverloadedTime() == turn)){ // overload req
            this->ecs->overloadRequest(setting->getElevatorNum());
        }

        else if(setting->getObstacle() && setting->getObstacleTime() == turn){ // obstacle req
            this->ecs->obstacleRequest(setting->getElevatorNum());
        }
    }
}

void SimulationManager::processBuildingSetting(int turn) {
    if((buildingSetting->getFire() && buildingSetting->getFireTime() == turn) ||
        (buildingSetting->getPowerOutage() && buildingSetting->getPowerOutageTime() == turn)){
        this->ecs->emergencyRequest(buildingSetting->getSafeFloors());
    }
}

void SimulationManager::processPassengerSetting(int turn){

    for(auto &setting : passengerSettings){
        int tFloorPressed = setting->getTimeFloorPressed();
        int tHelpPressed = setting->getTimeHelpPressed();
        int tOpenPressed = setting->getTimeOpenDoorPressed();
        int tClosePressed = setting->getTimeCloseDoorPressed();

        if(tFloorPressed > 0 && tFloorPressed == turn) this->passengerFloorPress(*setting);

	// Only if they're on the elevator, else increment that to the next turn
        if(tHelpPressed > 0 && tHelpPressed == turn && setting->getHelpPressed()) this->passengerHelpPress(*setting);
        if(tOpenPressed > 0 && tOpenPressed == turn && setting->getOpenDoorPressed()) this->passengerOpenDoorPress(*setting);
        if(tClosePressed > 0 && tClosePressed == turn && setting->getCloseDoorPressed()) this->passengerCloseDoorPress(*setting);
    }
}

// Passengers
void SimulationManager::passengerFloorPress(PassengerSetting &setting){
    Passenger *p = this->passengers[setting.getPassengerNum()];
    Floor *f = this->floors[setting.getStartFloor() - 1];
    Direction dir = setting.getDirection();
    Button *button = dir == Direction::Up ? f->getFloorUpButton(): f->getFloorDownButton();
    p->wait();
    p->pressButton(*button);
}

void SimulationManager::passengerHelpPress(PassengerSetting &setting){
    Passenger *p = this->passengers[setting.getPassengerNum()];
    if(p == nullptr || !p->isRiding()){
        setting.setTimeHelpPressed(setting.getTimeHelpPressed() + 1);
        return;
    }

    Elevator *e = this->elevators[p->getElevatorNum()];
    if(e != nullptr){
        Button *b = e->getHelpButton();
        p->pressButton(*b);
    }
}

void SimulationManager::passengerOpenDoorPress(PassengerSetting &setting){
    Passenger *p = this->passengers[setting.getPassengerNum()];
    if(p == nullptr || !p->isRiding()){
        setting.setTimeOpenDoorPressed(setting.getTimeOpenDoorPressed() + 1);
        return;
    }

    Elevator *e = this->elevators[p->getElevatorNum()];
    if(e != nullptr) {
	Button *b = e->getOpenButton();
        p->pressButton(*b);
    }
}

void SimulationManager::passengerCloseDoorPress(PassengerSetting &setting){
    Passenger *p = this->passengers[setting.getPassengerNum()];
    if(p == nullptr || !p->isRiding()){
        setting.setTimeCloseDoorPressed(setting.getTimeCloseDoorPressed() + 1);
        return;
    }

    Elevator *e = this->elevators[p->getElevatorNum()];
    if(e != nullptr){
        Button *b = e->getCloseButton();
        p->pressButton(*b);
    }
}

void SimulationManager::updatePassengers() {

    for(auto &pass : passengers){

        PassengerState state = pass->getState();
        int floorNum = pass->getFloorNum();
        int destNum = pass->getDestinationFloor();
        int passElevatorNum = pass->getElevatorNum();

        switch(state){
            case PassengerState::Arrived: // arrived don't do anything
                break;

            case PassengerState::Riding:
                for(auto &el : elevators){
                    ElevatorState es = el->getState();
                    if(es == ElevatorState::Stopped && el->isEmergency()) { // emergency so exit at currFloor
                        pass->exitElevator(el->getFloorNum());
                        el->removePassenger();
                    }
                    else if(
                        el->getElevatorNum() == passElevatorNum &&
                        es == ElevatorState::Stopped &&
                        el->getFloorNum() == destNum
                    ){
                        pass->exitElevator(destNum);
                        el->removePassenger();
                    }
                }
                break;

            case PassengerState::Waiting:
                for(auto &el : elevators){
                    if(
                        !el->isEmergency() &&
                        el->getState() == ElevatorState::Stopped &&
                        el->getFloorNum() == floorNum
                    ){
                        pass->boardElevator(el->getElevatorNum());
                        el->addPassenger();

                        // have passenger press destination button
                        Button *btn = el->getDestinationButton(destNum);
                        if(btn != nullptr){
                            pass->pressButton(*btn);
                        }
                    }
                }
                break;

            default:
                break; // noop (if away, don't update them)
        }
    }
}

