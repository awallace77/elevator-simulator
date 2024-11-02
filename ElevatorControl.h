#ifndef ELEVATOR_CONTROL_H
#define ELEVATOR_CONTROL_H

#include "Elevator.h"
#include "Direction.h"
#include "AllocationStrategy.h"
#include "NCStrategy.h"

class AllocationStrategy;

class ElevatorControl {

    public:
	ElevatorControl();
	~ElevatorControl();

	void floorRequest(int, Direction);
	void carRequest(int, int);

	void init(std::vector<Elevator*>, int);
	void setElevators(std::vector<Elevator*>);
	void setNumFloors(int);
	void moveElevators();

    private: 
	std::vector<Elevator*> elevators;
	std::map<int, std::vector<int>> elevatorTasks;
	AllocationStrategy *allocationStrategy;
	int numFloors;

	void moveIdle();
	bool canMove(int, Direction);

};
#endif
