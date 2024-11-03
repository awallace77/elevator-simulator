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
    Elevator *elevator = allocationStrategy->allocate(fq, elevators, floors.size());
    elevatorFloorTasks[elevator->getElevatorNumber()].push_back(fq);
}

void ElevatorControl::init(std::vector<Elevator*> elevators, std::vector<Floor*> floors) {
    setElevators(elevators);
    setFloors(floors);
}

void ElevatorControl::setElevators(std::vector<Elevator*> elevators) {
    this->elevators.clear();
    for(auto &el : elevators) this->elevators.push_back(el);
}

void ElevatorControl::setFloors(std::vector<Floor*> floors) {
    this->floors.clear();
    for(auto &el : floors) this->floors.push_back(el);
}

void ElevatorControl::moveIdle() {
    for(auto &el : elevators) {
    if(el->getState() == ElevatorState::Idle){
	    Direction dir = Random::rand() == 0 ? Direction::Up : Direction::Down;
        if(el->getFloor() >= static_cast<int>(floors.size()) && dir == Direction::Up) el->start(Direction::Down);
        else if(el->getFloor() <= 0 && dir == Direction::Down) el->start(Direction::Up);
        else el->start(dir);
	}
    }
}

void ElevatorControl::moveElevators() {
    for (auto &el : elevators) {
        auto &floorTasks = elevatorFloorTasks[el->getElevatorNumber()];
        auto &destTasks = elevatorDestTasks[el->getElevatorNumber()];

	int prevFloor = el->getFloor();
	el->move();
	int currFloor= el->getFloor();

    for(std::vector<FloorRequest*>::iterator it = floorTasks.begin(); it != floorTasks.end();){

        if(currFloor == (*it)->getFloor()) {

	    if(el->getDirection() != (*it)->getDirection()) {
		// check if there are any other floor requests w the same direction, continue
		bool hasOtherTask = false;
		for(auto &floorReq : floorTasks){
		    if(floorReq->getDirection() == el->getDirection()){
			hasOtherTask = true;
			break;
		    }
		}

		if(hasOtherTask){ // has another task so continue
		    ++it;
		    continue;
		} 
		    
		el->setDirection((*it)->getDirection());
	    }

		el->stop();
		floors[currFloor]->serviced(el->getDirection());
		it = floorTasks.erase(it); // remove task

	    }else{
		++it;
	    }
	}
    }
}

bool ElevatorControl::canMove(int elCurrFloor, Direction dir){
    if(elCurrFloor >= static_cast<int>(floors.size()) && dir == Direction::Up) return false;
    if(elCurrFloor <= 0 && dir == Direction::Down) return false;
    return true;
}

