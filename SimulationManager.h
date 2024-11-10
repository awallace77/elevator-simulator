#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "Elevator.h"
#include "Passenger.h"
#include "Floor.h"
#include "ElevatorSetting.h"
#include "PassengerSetting.h"
#include "BuildingSetting.h"
#include "ElevatorControl.h"
#include "SimulationUpdater.h"
#include <QTimer>

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

        ~SimulationManager();
        bool runTurn(int);

    private:
        bool hasBuildingSetting(int);
        bool hasElevatorSetting(int);
        bool hasPassengerSetting(PassengerSetting&);

        bool shouldContinue(int);

        // Settings
        void processBuildingSetting(int);
        void processElevatorSetting(int);
        void processPassengerSetting(int);

        // Elevators
        void moveElevators();
        void startElevators();

        // Passengers
        void passengerFloorPress(PassengerSetting&);
        void passengerHelpPress(PassengerSetting&);
        void passengerOpenDoorPress(PassengerSetting&);
        void passengerCloseDoorPress(PassengerSetting&);
        void updatePassengers();

        // UI
        void updateUI();

        std::vector<Elevator*> elevators;
        std::vector<Passenger*> passengers;
        std::vector<Floor*> floors;
        std::vector<ElevatorSetting*> elevatorSettings;
        std::vector<PassengerSetting*> passengerSettings;
        BuildingSetting *buildingSetting;
        ElevatorControl *ecs;
        SimulationUpdater *simUpdater;
        QTimer *timer;
};

#endif
