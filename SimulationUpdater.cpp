#include "SimulationUpdater.h"

SimulationUpdater::SimulationUpdater() {}
SimulationUpdater::~SimulationUpdater() {}

void SimulationUpdater::updateUI(std::vector<Elevator*> &elevators, std::vector<Passenger*> &passengers, std::vector<Floor*> &floors) {
    for(auto &el : elevators) el->updateUI();
    for(auto &p : passengers) p->updateUI();
    for(auto &f : floors) f->updateUI();
}

