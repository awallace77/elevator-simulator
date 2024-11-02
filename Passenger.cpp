#include "Passenger.h"
#include "ui_Passenger.h"

Passenger::Passenger(int passengerNum, int floorNum, int destinationFloor, QWidget *parent) :
    SimulationComponent(parent),
    ui(new Ui::Passenger)
{
    ui->setupUi(this);
    this->passengerNum = passengerNum;
    this->state = PassengerState::Waiting;
    this->floorNum = floorNum;
    this->elevatorNum = -1; // we don't know initally
    this->destinationFloor = destinationFloor;

    Passenger::initUI();
}

Passenger::~Passenger() {
    delete ui;
}

void Passenger::initUI() {
    Passenger::updateUI();
}

QString Passenger::getState() const {
    switch(this->state){
	case PassengerState::Waiting:
	    return "Waiting";
	case PassengerState::Riding:
	    return "Riding";
	case PassengerState::Arrived:
	    return "Arrived";
	default:
	    return "Unknown State";
    }
}

bool Passenger::isWaiting() const {
    return this->state == PassengerState::Waiting;
}

bool Passenger::isRiding() const {
    return this->state == PassengerState::Riding;
}

bool Passenger::hasArrived() const {
    return this->state == PassengerState::Arrived;
}

void Passenger::pressButton(Button &button){
    qInfo() << "Button Pressed";
    button.press();
}

void Passenger::boardElevator(int elevatorNum) {
    this->setElevatorNum(elevatorNum);
    this->state = PassengerState::Riding;
}

void Passenger::exitElevator(int floorNum) {
    this->setFloorNum(floorNum);
    this->state = PassengerState::Arrived;
}

void Passenger::setPassengerNum(int num) { 
    this->passengerNum = num; 
}

void Passenger::setFloorNum(int num) { 
    this->floorNum = num; 
}

void Passenger::setElevatorNum(int num ) {
    this->elevatorNum = num;
}

void Passenger::setDestinationFloor(int num) { 
    this->destinationFloor = num; 
}

void Passenger::updateUI() {
    ui->passengerLabel->setText(QString("Passenger %1").arg(this->passengerNum + 1));
    ui->stateLabel->setText(this->getState());
    ui->currentFloorLabel->setText(QString("Floor %1").arg(this->floorNum));
}


