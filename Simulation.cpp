#include "Simulation.h"
#include "ui_Simulation.h"

#include <QEventLoop>

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simulation) {
    ui->setupUi(this);
    
    simManager = nullptr;
    ecs = nullptr;
    timer = new QTimer();
    turn = 1;

    connect(timer, &QTimer::timeout, this, &Simulation::runTurn);
}

Simulation::~Simulation() {
    delete ui;
    for(auto &elevator : elevators) delete elevator;
    for(auto &passenger : passengers) delete passenger;
    for(auto &floor : floors) delete floor;
    delete simManager;
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
    //this->end();
}

void Simulation::startSimulation() {
    qInfo() << "Simulation Started";
    bool run = true;
    while(run){

        // Pause for 3 seconds without blocking
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();


        runTurn();
	if(turn == 3) break;

	++turn;

    }
}

void Simulation::runTurn(){
    simManager->runTurn(turn);
    this->updateUI(turn);
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
    ecs->init(elevators, floors);

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
    this->initElevatorsUI();
    this->initPassengersUI();
    this->initFloorsUI();
}

void Simulation::updateUI(int turn) {
    this->updateElevatorsUI();
    this->updatePassengersUI();
    this->updateFloorsUI();
    ui->statusLabel->setText("Running");
    ui->timeLcdNumber->display(turn);
}

void Simulation::initElevatorsUI() {
    for(auto &elevator : this->elevators){
	ui->elevatorLayout->addWidget(elevator);
    }
}

void Simulation::initPassengersUI() {
    for(auto &passenger : this->passengers){
	ui->passengerLayout->addWidget(passenger);
    }
}

void Simulation::initFloorsUI() {
    for(auto &floor : this->floors){
	ui->floorLayout->addWidget(floor);
    }
}

void Simulation::updateElevatorsUI() {
    for(auto &elevator : this->elevators){
	elevator->updateUI();
    }
}

void Simulation::updatePassengersUI() {
    for(auto &passenger : this->passengers){
	passenger->updateUI();
    }
}

void Simulation::updateFloorsUI() {
    for(auto &floor : this->floors){
	floor->updateUI();
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

