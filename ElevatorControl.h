#ifndef ELEVATOR_CONTROL_H
#define ELEVATOR_CONTROL_H

#include "Elevator.h"
#include "Direction.h"
#include "AllocationStrategy.h"
#include "NCStrategy.h"
#include "FloorRequest.h"
#include "Floor.h"

class Floor;

class ElevatorControl {

    public:
	ElevatorControl();
	~ElevatorControl();

	void floorRequest(int, Direction);
	void carRequest(int, int);

    void init(std::vector<Elevator*>, std::vector<Floor*>);
	void setElevators(std::vector<Elevator*>);
    void setFloors(std::vector<Floor*>);
    void moveElevators();

    private: 
	std::vector<Elevator*> elevators;
    std::vector<Floor*> floors;
	std::map<int, std::vector<FloorRequest*>> elevatorFloorTasks;
	std::map<int, std::vector<int>> elevatorDestTasks;
	AllocationStrategy *allocationStrategy;

	void moveIdle();
	bool canMove(int, Direction);

};
#endif
