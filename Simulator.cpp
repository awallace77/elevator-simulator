
#include "Simulator.h"
#include <QDebug>

Simulator::Simulator() {}

Simulator::~Simulator(){ }


void Simulator::start(std::vector<Elevator*> elevators, std::vector<PassengerSetting*> passengerSettings) {
	for(auto &el : elevators){
        qInfo() << el->toString();
	}
	
	for(auto &ps : passengerSettings){
        qInfo() << ps->toString();
	}
}
