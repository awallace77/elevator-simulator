#include "NCStrategy.h"
#include <QDebug>
#include "Random.h"

NCStrategy::NCStrategy() {}
NCStrategy::~NCStrategy(){}

// See vedantmisra.com/elevator-algorithms for details
Elevator* NCStrategy::allocate(FloorRequest *req, std::vector<Elevator*> &elevators, int numFloors) {

    int elIndex = 0;
    int bestScore = -1;
    int bestElNumPassengers = -1;

    int reqOrigin = req->getFloorNum();
    Direction reqDirection = req->getDirection();

    for(size_t i = 0; i < elevators.size(); i++){
        int elFloor = elevators[i]->getFloorNum();
        Direction elDirection = elevators[i]->getDirection();
        int elNumPassengers = elevators[i]->getNumPassengers();

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
            bestElNumPassengers = elNumPassengers;
        }

        else if(fs == bestScore){
            if(elNumPassengers < bestElNumPassengers) { // give it to the elevator with less passengers
            bestScore = fs;
            elIndex = i;
            bestElNumPassengers = elNumPassengers;
            }

            else if(Random::rand() == 0) { // in the event of a complete tie, randomize the allocation
            bestScore = fs;
            elIndex = i;
            bestElNumPassengers = elNumPassengers;
            }
        }
    }

    return elevators[elIndex];
}

