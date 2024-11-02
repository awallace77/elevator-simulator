#include "simulationinitializer.h"
#include <QDebug>

SimulationInitializer::SimulationInitializer(QObject* parent): QObject(parent) {}

void SimulationInitializer::updatePassengers(int numPassengers) {
    if(static_cast<std::vector<int>::size_type>(numPassengers) < this->passengers.size()){
        this->removePassenger();
    } else if(static_cast<std::vector<int>::size_type>(numPassengers) > this->passengers.size()) {
        this->addPassenger();
    }
}

void SimulationInitializer::addPassenger() {
    qInfo("Adding new Passenger");
    this->passengers.push_back(new Passenger());
}

void SimulationInitializer::removePassenger() {
    qInfo("Removing Passenger");
    this->passengers.pop_back();
}

void SimulationInitializer::addFloor() {
    qInfo("Adding new Floor");
    this->floors.push_back(new Floor());
}

void SimulationInitializer::removeFloor() {
    qInfo("Removing Floor");
    this->floors.pop_back();
}

void SimulationInitializer::addElevator() {
    qInfo("Adding new Elevator");
    this->elevators.push_back(new Elevator());
}

void SimulationInitializer::removeElevator() {
    qInfo("Removing Elevator");
    this->elevators.pop_back();
}

