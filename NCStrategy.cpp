#include "NCStrategy.h"
#include <QDebug>

NCStrategy::NCStrategy() {
    qInfo() << "Allocation Strategy Created";
}

// See vedantmisra.com/elevator-algorithms for details
Elevator* NCStrategy::allocate(FloorRequest *req, std::vector<Elevator*> elevators, int numFloors) {

    int elIndex = 0;
    int bestScore = -1;

    int reqOrigin = req->getOrigin();
    Direction reqDirection = req->getDirection();

    int i = 0;
    for(auto &el : elevators){
	int elFloor = el[i].getFloor();
	Direction elDirection = el[i].getDirection();

	int fs = -1; // figure of suitability
	
	// moving towards call
	if(elFloor <= reqOrigin && elDirection == reqDirection){
	    fs = ((numFloors - 1) + 2) - abs(elFloor - reqOrigin);
	}

	// moving towards call but opposite direction
	else if(elFloor <= reqOrigin && elDirection != reqDirection){
	    fs = ((numFloors - 1) + 1) - abs(elFloor - reqOrigin);
	}
	
	else{ // moving away from the call
	    fs = 1;
	}

	if(fs > bestScore){ // highest fs will be allocated
	    bestScore = fs;
	    elIndex = i;
	}

	++i;
    }

    return elevators[elIndex];
}

