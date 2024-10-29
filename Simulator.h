#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Elevator.h"
#include "PassengerSetting.h"

class Simulator {

    public: 
	Simulator();
	~Simulator();

	void start(std::vector<Elevator*>, std::vector<PassengerSetting*>);
};

#endif
