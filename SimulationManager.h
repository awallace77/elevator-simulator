#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "Elevator.h"
#include "Passenger.h"
#include "Floor.h"
#include "ElevatorSetting.h"
#include "PassengerSetting.h"
#include "BuildingSetting.h"
#include "ElevatorControl.h"

class SimulationManager {

    public:
	SimulationManager(
	    std::vector<Elevator*>,
	    std::vector<Passenger*>,
	    std::vector<Floor*>,
	    std::vector<ElevatorSetting*>,
	    std::vector<PassengerSetting*>,
	    BuildingSetting*,
	    ElevatorControl*
	);

	void runTurn(int);
    private:
	// turn number, elevator settings, passenger settings, building settings
	bool hasBuildingSetting(int);
	bool hasElevatorSetting(int);
	bool hasPassengerSetting(PassengerSetting&);
	
	void processBuildingSetting(int);
	void processElevatorSetting(int);
	void processPassengerSetting(int);

	void passengerFloorPress(PassengerSetting&);
	void passengerHelpPress(PassengerSetting&);
	void passengerOpenDoorPress(PassengerSetting&);
	void passengerCloseDoorPress(PassengerSetting&);

	std::vector<Elevator*> elevators;
	std::vector<Passenger*> passengers;
	std::vector<Floor*> floors;
	std::vector<ElevatorSetting*> elevatorSettings;
	std::vector<PassengerSetting*> passengerSettings;
	BuildingSetting *buildingSetting;
	ElevatorControl *ecs;
};

#endif
