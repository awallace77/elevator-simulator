#ifndef ALLOCATION_STRAT_H
#define ALLOCATION_STRAT_H

#include "FloorRequest.h"
#include "Elevator.h"

class AllocationStrategy {

    public:
	virtual Elevator* allocate(FloorRequest *request, std::vector<Elevator*>, int) = 0;
};

#endif
