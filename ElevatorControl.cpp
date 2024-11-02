#include "ElevatorControl.h"
#include "Random.h"
#include <QDebug>

ElevatorControl::ElevatorControl() {
    qInfo() << "Created Elevator Control";
    for(auto &el : elevators) elevators.push_back(el);
    allocationStrategy = new NCStrategy();
}

ElevatorControl::~ElevatorControl() {
    qInfo() << "Destructing Elevator Control";
}

void ElevatorControl::floorRequest(int floor, Direction dir){
    moveIdle();
    
    FloorRequest *fq = new FloorRequest(floor, dir);
    Elevator *elevator = allocationStrategy->allocate(fq, elevators, numFloors);
    elevatorTasks[elevator->getElevatorNumber()].push_back(floor);

    delete fq;
}

void ElevatorControl::init(std::vector<Elevator*> elevators, int numFloors) {
    setElevators(elevators);
    setNumFloors(numFloors);
}

void ElevatorControl::setElevators(std::vector<Elevator*> elevators) {
    this->elevators.clear();
    for(auto &el : elevators) this->elevators.push_back(el);
}
    
void ElevatorControl::setNumFloors(int numFloors) {
    this->numFloors = numFloors;
}

void ElevatorControl::moveIdle() {
    for(auto &el : elevators) {
    if(el->getState() == ElevatorState::Idle){
	    Direction dir = Random::rand() == 0 ? Direction::Up : Direction::Down;
        if(el->getFloor() >= numFloors && dir == Direction::Up) el->start(Direction::Down);
        else if(el->getFloor() <= 0 && dir == Direction::Down) el->start(Direction::Up);
        else el->start(dir);
	}
    }
}

void ElevatorControl::moveElevators() {
    for (auto &el : elevators) {
        ElevatorState elState = el->getState();
        auto &elTasks = elevatorTasks[el->getElevatorNumber()]; // Use a reference

        bool stopped = false;
        switch (elState) {
            case ElevatorState::Idle:
                if (!elTasks.empty()) { // Check if there are tasks
                    int floor = elTasks[0];
                    int elFloor = el->getFloor();

                    if (elFloor != floor) {
                        el->start(floor < elFloor ? Direction::Down : Direction::Up);
                        this->canMove(elFloor, el->getDirection()) ? el->move() : el->setIdle();
                    } else {
                        el->stop();
                    }
                }
                break;

            case ElevatorState::Moving:
                for (size_t i = 0; i < elTasks.size(); i++) {
                    if (el->getFloor() == elTasks[i]) {
                        stopped = true;
                        elTasks.erase(elTasks.begin() + i); // Modify original tasks
                    }
                }

                if (stopped) {
                    el->stop();
                } else {
                    this->canMove(el->getFloor(), el->getDirection()) ? el->move() : el->setIdle();
                }
                break;


            default:
                break;
        }
    }
}

bool ElevatorControl::canMove(int elCurrFloor, Direction dir){
    if(elCurrFloor >= numFloors && dir == Direction::Up) return false;
    if(elCurrFloor <= 0 && dir == Direction::Down) return false;
    return true;
}

