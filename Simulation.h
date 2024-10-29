#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDialog>
#include <QLayout>
#include "ElevatorSetting.h"
#include "PassengerSetting.h"
#include "BuildingSetting.h"

#include "Elevator.h"
#include "Passenger.h"
#include "Floor.h"
#include "ElevatorControl.h"

namespace Ui {
class Simulation;
}

class Simulation : public QDialog {
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    ~Simulation();

    void start(
	std::vector<ElevatorSetting*>, 
	std::vector<PassengerSetting*>, 
	BuildingSetting*,
	int,
	int,
	int
    );

private:
    Ui::Simulation *ui;

    // settings
    std::vector<ElevatorSetting*> elevatorSettings;
    std::vector<PassengerSetting*> passengerSettings;
    BuildingSetting* buildingSetting;

    // creates
    std::vector<Elevator*> elevators;
    std::vector<Passenger*> passengers;
    std::vector<Floor*> floors;
    ElevatorControl *ecs;

    int numElevators;
    int numPassengers;
    int numFloors;
    void init(
	std::vector<ElevatorSetting*>, 
	std::vector<PassengerSetting*>, 
	BuildingSetting*,
	int,
	int,
	int
    );

    void startSimulation();

    // Init 
    void initElevators(std::vector<ElevatorSetting*>, int);
    void initPassengers(std::vector<PassengerSetting*>, int);
    void initFloors(int);
    void addElevator(int);
    void addPassenger(int);
    void addFloor(int);

    // UI 
    void initUI();
    void updateUI();
    void updateElevators();
    void updatePassengers();
    void updateFloors();

    // Running
    //TurnInfo getTurnInfo();

    void clearLayout(QLayout*);
};

#endif // SIMULATION_H