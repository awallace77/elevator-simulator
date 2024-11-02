#include "Simulation.h"
#include "ui_Simulation.h"

Simulation::Simulation(
	std::vector<ElevatorSetting*> elevatorSettings,
	std::vector<PassengerSetting*> passengerSettings,
	BuildingSetting* buildingSetting,
	int numElevators,
	int numPassengers,
    int numFloors,
	QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simulation) {
    ui->setupUi(this);
    this->init(elevatorSettings, passengerSettings, buildingSetting, numElevators, numPassengers, numFloors);
}

Simulation::~Simulation() {
    delete ui;
}

// Running Simulation
void Simulation::start(
    //std::vector<ElevatorSetting*> elevatorSettings,
    //std::vector<PassengerSetting*> passengerSettings,
    //BuildingSetting* buildingSetting,
    //int numElevators,
    //int numPassengers,
    //int numFloors
){
    //this->startSimulation();
    //this->end();
}

void Simulation::startSimulation() {
    qInfo() << "Simulation Started";
    bool run = true;
    int turn = 1;
    while(run){
	simManager->runTurn(turn++);
	if(turn == 3) run = false;
    }
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

    ecs = new ElevatorControl();
    this->initElevators(elevatorSettings, numElevators);
    this->initPassengers(passengerSettings, numPassengers);
    this->initFloors(numFloors);
    ecs->init(elevators, numFloors);

    simManager = new SimulationManager(
	elevators,
	passengers,
	floors,
	elevatorSettings,
	passengerSettings,
	buildingSetting,
	ecs
    );
    this->initUI();
}

void Simulation::end() {
    for(auto &elevator : elevators) delete elevator;
    for(auto &passenger : passengers) delete passenger;
    for(auto &floor : floors) delete floor;
    delete simManager;
    delete ecs;
    qInfo() << "Simulation ended";
}

void Simulation::initElevators(std::vector<ElevatorSetting*> settings, int num){
    qInfo() << "initalizing elevators";
   
    this->elevators.clear();
    for(std::vector<ElevatorSetting*>::size_type i = 0; i < settings.size(); i++){
	this->addElevator(i, 0, settings[i]->getCapacity(), ecs, this);
	// elevator num, floorNum, capacity, QWidget *parent
    }
}

void Simulation::initPassengers(std::vector<PassengerSetting*> settings, int num){
    qInfo() << "initalizing passengers";
    this->passengers.clear();
    for(std::vector<ElevatorSetting*>::size_type i = 0; i < settings.size(); i++){
	this->addPassenger(i, settings[i]->getStartFloor(), settings[i]->getDestinationFloor(), this);
	// elevator num, floorNum, destinationFloor, QWidget *parent
    }
}

void Simulation::initFloors(int num){
    qInfo() << "initalizing floors";
    this->floors.clear();
    for(int i = 0; i < num; i++){
	this->addFloor(i, ecs, this);
    }
}

void Simulation::addElevator(int num, int floorNum, int capacity, ElevatorControl *ecs, QWidget *parent) {
    Elevator *newElevator = new Elevator(num, floorNum, capacity, ecs, parent);
    this->elevators.push_back(newElevator);
}

void Simulation::addPassenger(int num, int floorNum, int destFloor, QWidget *parent) {
    Passenger *newPassenger = new Passenger(num, floorNum, destFloor, parent);
    this->passengers.push_back(newPassenger);
}

void Simulation::addFloor(int num, ElevatorControl *ecs, QWidget *parent) {
    Floor *newFloor = new Floor(num, ecs, parent);
    this->floors.push_back(newFloor);
}

// UI 
void Simulation::initUI() {
    this->clearSimulation();
    this->updateElevators();
    this->updatePassengers();
    this->updateFloors();
}

void Simulation::updateElevators() {
    for(auto &elevator : this->elevators){
        //elevator->show();
    ui->elevatorLayout->addWidget(elevator);
    }
}

void Simulation::updatePassengers() {
    for(auto &passenger : this->passengers){
    //passenger->show();
	ui->passengerLayout->addWidget(passenger);
    }
}

void Simulation::updateFloors() {
    for(auto &floor : this->floors){
    //floor->show();
	ui->floorLayout->addWidget(floor);
    }
}

void Simulation::clearSimulation(){
    this->clearLayout(ui->elevatorLayout);
    this->clearLayout(ui->passengerLayout);
    this->clearLayout(ui->floorLayout);
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

