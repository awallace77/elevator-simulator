#include "Simulation.h"
#include "ui_Simulation.h"

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simulation) {
    ui->setupUi(this);
    ecs = new ElevatorControl();
}

Simulation::~Simulation() {
    delete ui;
    for(auto &elevator : elevators) delete elevator;
    for(auto &passenger : passengers) delete passenger;
    for(auto &floor : floors) delete floor;
    delete ecs;
}


// Running Simulation
void Simulation::start(
    std::vector<ElevatorSetting*> elevatorSettings,
    std::vector<PassengerSetting*> passengerSettings,
    BuildingSetting* buildingSetting,
    int numElevators,
    int numPassengers,
    int numFloors
){
    this->init(elevatorSettings, passengerSettings, buildingSetting, numElevators, numPassengers, numFloors);
    this->startSimulation();
}

void Simulation::startSimulation() {
    qInfo() << "Simulation Started";
}

// Initialization
void Simulation::init(
	std::vector<ElevatorSetting*> elevatorSettings,
	std::vector<PassengerSetting*> passengerSettings,
	BuildingSetting* buildingSetting,
	int numElevators,
	int numPassengers,
	int numFloors
) {

    for(auto &setting : elevatorSettings) this->elevatorSettings.push_back(setting);
    for(auto &setting : passengerSettings) this->passengerSettings.push_back(setting);
    this->buildingSetting = buildingSetting;

    this->initElevators(elevatorSettings, numElevators);
    this->initPassengers(passengerSettings, numPassengers);
    this->initFloors(numFloors);
}

void Simulation::initElevators(std::vector<ElevatorSetting*> settings, int num){
    qInfo() << "initalizing elevators";
}

void Simulation::initPassengers(std::vector<PassengerSetting*> settings, int num){
    qInfo() << "initalizing passengers";
}

void Simulation::initFloors(int num){
    qInfo() << "initalizing floors";
}

void Simulation::addElevator(int num) {
    Elevator *newElevator = new Elevator(num, num, num, this);
    this->elevators.push_back(newElevator);
}

void Simulation::addPassenger(int num) {
    Passenger *newPassenger = new Passenger(num, num, num, this);
    this->passengers.push_back(newPassenger);
}

void Simulation::addFloor(int num) {
    Floor *newFloor = new Floor(num, this);
    this->floors.push_back(newFloor);
}

// UI 
void Simulation::updateElevators() {
    this->elevators.clear();
    for(int i = 0; i < numElevators; i++){
	this->addElevator(i);
    }
}

void Simulation::clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}
