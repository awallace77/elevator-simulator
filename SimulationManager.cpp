
#include "SimulationManager.h"

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
}

void SimulationManager::runTurn(int turn){

    // Building settings are priority
    // Any would trigger end of simulation scenario


    // Elevator settings are next
    // Any would cause others to wait
    

    // Passenger Setttings last
    processPassengerSetting(turn);
    moveElevators();
}

void SimulationManager::moveElevators() {
    ecs->moveElevators();
}

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

void SimulationManager::processPassengerSetting(int turn){

    for(auto &setting : passengerSettings){
        int tFloorPressed = setting->getTimeFloorPressed();
        int tHelpPressed = setting->getTimeHelpPressed();
        int tOpenPressed = setting->getTimeOpenDoorPressed();
        int tClosePressed = setting->getTimeCloseDoorPressed();

        if(tFloorPressed > 0 && tFloorPressed == turn) this->passengerFloorPress(*setting);
        if(tHelpPressed > 0 && tHelpPressed == turn && setting->getHelpPressed()) this->passengerHelpPress(*setting);
        if(tOpenPressed > 0 && tOpenPressed == turn && setting->getOpenDoorPressed()) this->passengerOpenDoorPress(*setting);
        if(tClosePressed > 0 && tClosePressed == turn && setting->getCloseDoorPressed()) this->passengerCloseDoorPress(*setting);
    }
}


void SimulationManager::passengerFloorPress(PassengerSetting &setting){
    Passenger *p = this->passengers[setting.getPassengerNum()];
    Floor *f = this->floors[setting.getStartFloor()];
    Direction dir = setting.getDirection();
    Button *button = dir == Direction::Up ? f->getFloorUpButton(): f->getFloorDownButton();
    p->pressButton(*button);
}

void SimulationManager::passengerHelpPress(PassengerSetting &setting){
//TODO
}

void SimulationManager::passengerOpenDoorPress(PassengerSetting &setting){
//TODO
}

void SimulationManager::passengerCloseDoorPress(PassengerSetting &setting){
//TODO
}
