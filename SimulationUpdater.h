#ifndef SIMULATION_UPDATER_H
#define SIMULATION_UPDATER_H

#include "Elevator.h"
#include "Passenger.h"
#include "Floor.h"

class SimulationUpdater {

    public:
        SimulationUpdater();
        ~SimulationUpdater();
        void updateUI(std::vector<Elevator*>&, std::vector<Passenger*>&, std::vector<Floor*>&);
};

#endif
