#include "ElevatorControl.h"
#include "Random.h"
#include <QDebug>
#include <cmath>
#include <limits>

ElevatorControl::ElevatorControl() {
    allocationStrategy = new NCStrategy();
}

ElevatorControl::~ElevatorControl() {
    delete allocationStrategy;
}

void ElevatorControl::floorRequest(int floor, Direction dir){
    moveIdle();
    
    FloorRequest *fq = new FloorRequest(floor, dir);
    Elevator *elevator = allocationStrategy->allocate(fq, elevators, floors.size());
    elevatorFloorTasks[elevator->getElevatorNum()].push_back(fq);
}

void ElevatorControl::carRequest(int car, int dest) {
    elevatorDestTasks[car].push_back(dest);
}

void ElevatorControl::overloadRequest(int car) {
    if(car < 0 || car >= static_cast<int>(elevators.size())) return;
    Elevator *el = elevators[car];
    if(el != nullptr) el->overloaded();
}

void ElevatorControl::obstacleRequest(int car) {
    if(car < 0 || car >= static_cast<int>(elevators.size())) return;
    Elevator *el = elevators[car];
    if(el != nullptr) el->obstacle();
}

void ElevatorControl::helpRequest(int car) {
    if(car < 0 || car >= static_cast<int>(elevators.size())) return;
    Elevator *el = elevators[car];
    if(el == nullptr) return;

    QString nineOneOne = "911 connected, please state your emergency";
    QString buildingSafety = "Building safety connected, please state your request";
   
    if(Random::rand() == 0) {
        el->connect(nineOneOne);
    } else {
        el->connect(buildingSafety);
    }
}

void ElevatorControl::emergencyRequest(const std::vector<int> &safeFloors) {
    // 1. Clear all elevator tasks
    for(auto &pair : elevatorFloorTasks){
        for(FloorRequest *fq : pair.second) delete fq;
        pair.second.clear();
    }

    for(auto &pair : elevatorDestTasks){
        pair.second.clear();
    }

    // 2. Find the closest safe floor for each elevator
    // 3. Set a destination request for the elevators' closest floor
    for(auto &pair : elevatorDestTasks){
        Elevator *el = elevators[pair.first];
        pair.second.push_back(findSafeFloor(safeFloors, *el)); // get the safe floor for that given elevator
    }

    // 5. set emergency status for each elevator
    for(Elevator *el : elevators){
        el->emergency();
    }
}

int ElevatorControl::findSafeFloor(const std::vector<int> &safeFloors, Elevator &el) {
    int elCurrFloor = el.getElevatorNum();
    int safeFloor = elCurrFloor;
    int lowestDelta = std::numeric_limits<int>::max();

    for(auto &floor : safeFloors) {
        if(floor == elCurrFloor){
            safeFloor = floor;
            break;
        }

        // the floor with the lowest delta
        int delta = std::abs(elCurrFloor - floor);
        if(delta < lowestDelta){
            safeFloor = floor;
            lowestDelta = delta;
        }
    }

    return safeFloor;
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
            if(el->getFloorNum() >= static_cast<int>(floors.size()) && dir == Direction::Up) el->start(Direction::Down);
            else if(el->getFloorNum() <= 0 && dir == Direction::Down) el->start(Direction::Up);
            else el->start(dir);
        }
    }
}

/* Function: shouldStop
 * Purpose: Removes the floor requests that will be serviced by stopping. Returns true if any have been removed.
 */
bool ElevatorControl::shouldStop(std::vector<FloorRequest*> &floorRequests, int currFloor, Direction &dir) {

    std::vector<FloorRequest*> fqsToDelete;
    fqsToDelete.clear();

    bool shouldStop = false;
    Direction newDir = dir;

    //for(std::vector<FloorRequest*>::iterator it = floorRequests.begin(); it != floorRequests.end();){
    for(auto &req : floorRequests) {
        if(req->getFloorNum() == currFloor) {
            if(req->getDirection() == dir) {
                fqsToDelete.push_back(req);
                shouldStop = true;
                newDir = dir;
               continue;
            }

            // different directions; so check if has floor requests above it, or below it, or at it, but in different directions
            bool hasOtherTask = false;
            for(auto &req : floorRequests) {
                int reqFloorNumber = req->getFloorNum();
                Direction reqDirection = req->getDirection();
                if(
                    (reqFloorNumber > currFloor && dir == Direction::Up) ||
                    (reqFloorNumber < currFloor && dir == Direction::Down) ||
                    (reqFloorNumber == currFloor && dir == reqDirection)
                ) hasOtherTask = true;
            }

            if(hasOtherTask) continue;

            fqsToDelete.push_back(req);
            newDir = req->getDirection();
            shouldStop = true;

        }
    }

    for (FloorRequest *ptr : fqsToDelete) {  // remove all the fqs from floorTasks ref
        
        auto it = std::find(floorRequests.begin(), floorRequests.end(), ptr);
        if (it != floorRequests.end()) {
            delete *it;
            floorRequests.erase(it);
            ptr = nullptr;
        }
    }

    dir = newDir;
    return shouldStop;
}

void ElevatorControl::moveElevators() {
    for (auto &el : elevators) {
        if(el->isSafety()) continue; // in safety mode, so don't move
        auto &floorTasks = elevatorFloorTasks[el->getElevatorNum()];
        auto &destTasks = elevatorDestTasks[el->getElevatorNum()];

        int prevFloor = el->getFloorNum();
        hasTasks(floorTasks, destTasks) && canMove(prevFloor, el->getDirection()) ? el->move() : el->rest();
        int currFloor= el->getFloorNum();
        Direction currDirection = el->getDirection();

        bool shouldStop = this->shouldStop(floorTasks, currFloor, currDirection);

        // Should stop?
        if(shouldStop){
            el->stop();
            floors[currFloor]->serviced(currDirection);

            for(std::vector<int>::iterator it = destTasks.begin(); it != destTasks.end();){ // remove destReq
                if(*it == currFloor) {
                    Button *destBtn = el->getDestinationButton(*it);
                    if(destBtn != nullptr) destBtn->off();
                    it = destTasks.erase(it);
                   }
                else ++it;
            }
        } else {// Check destination requests
            for(std::vector<int>::iterator it = destTasks.begin(); it != destTasks.end();) {
                if(currFloor == (*it)){
                    el->stop();
                    Button *destBtn = el->getDestinationButton(*it);
                    if(destBtn != nullptr) destBtn->off();
                    it = destTasks.erase(it); // remove task
                } else{
                    ++it;
                }
            }
        }
    }
}

void ElevatorControl::startElevators() {

    for(auto &el : elevators) {
        auto &floorTasks = elevatorFloorTasks[el->getElevatorNum()];
        auto &destTasks = elevatorDestTasks[el->getElevatorNum()];
        int currFloor= el->getFloorNum();
        Direction currDirection = el->getDirection();

        // start elevators in the necessary direction
        switch(currDirection){
            case Direction::Up:
                if (this->hasTasksInDirection(floorTasks, destTasks, currFloor, Direction::Up)) {
                    el->start(Direction::Up);
                } else if(this->hasTasksInDirection(floorTasks, destTasks, currFloor, Direction::Down)) {
                    el->start(Direction::Down); // move down instead
                } else {
                    el->rest();
                }
                break;

            case Direction::Down:
                if (this->hasTasksInDirection(floorTasks, destTasks, currFloor, Direction::Down)) {
                    el->start(Direction::Down);
                } else if(this->hasTasksInDirection(floorTasks, destTasks, currFloor, Direction::Up)) {
                    el->start(Direction::Up); // move up instead
                } else {
                    el->rest();
                }
                break;

            default:
                if(floorTasks.size() > 0) el->start(floorTasks[0]->getDirection());
                else if(destTasks.size() > 0) el->start(destTasks[0] < currFloor ? Direction::Down : Direction::Up);
                else  el->rest();
                break;
        }
    }
}

bool ElevatorControl::hasRequests() {

    for(const auto &pair : elevatorFloorTasks) {
        if(!pair.second.empty()) return true;
    }

    for(const auto &pair : elevatorDestTasks) {
        if(!pair.second.empty()) return true;
    }

    return false;
}

bool ElevatorControl::hasTasksInDirection(std::vector<FloorRequest*>& floorTasks, std::vector<int>& destTasks, int currFloor, Direction dir) {
    if(dir == Direction::Up) {
        for(const auto& task : floorTasks) {
            if (task->getFloorNum() > currFloor) return true;
        }
        for(const auto& task : destTasks) {
            if(task > currFloor) return true;
        }
    } else if(dir == Direction::Down) {
        for(const auto& task : floorTasks) {
            if(task->getFloorNum() < currFloor) return true;
        }
        for(const auto& task : destTasks) {
            if(task < currFloor) return true;
        }
    }
    return false;
}

bool ElevatorControl::hasTasks(std::vector<FloorRequest*>& floorTasks, std::vector<int>& destTasks) {
   return (floorTasks.size() > 0 || destTasks.size() > 0);
}

bool ElevatorControl::canMove(int elCurrFloor, Direction dir){
    if(elCurrFloor >= (static_cast<int>(floors.size()) - 1) && dir == Direction::Up) return false;
    if(elCurrFloor <= 0 && dir == Direction::Down) return false;
    return true;
}

QString ElevatorControl::vectorToString(std::vector<int>& vec) {
    QString result;
    QTextStream stream(&result);
    
    stream << "[";
    bool firstValue = true;
    for (const auto& value : vec) {
        if (!firstValue) {
            stream << ", ";
        }
        stream << value;
        firstValue = false;
    }
    stream << "]";
    
    return result;
}

QString ElevatorControl::vectorToString(std::vector<FloorRequest*>& vec) {
    QString result;
    QTextStream stream(&result);
    
    stream << "[";
    bool firstValue = true;
    for (const auto& value : vec) {
        if (!firstValue) {
            stream << ", ";
        }
        stream << value->getFloorNum() << " :: " << (value->getDirection() == Direction::Up ? "Up" : "Down");
        firstValue = false;
    }
    stream << "]";
    
    return result;
}
