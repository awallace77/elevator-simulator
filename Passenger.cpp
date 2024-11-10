#include "Passenger.h"
#include "ui_Passenger.h"

Passenger::Passenger(int passengerNum, int floorNum, int destinationFloor, Direction dir, QWidget *parent) :
    SimulationComponent(parent),
    ui(new Ui::Passenger)
{
    ui->setupUi(this);
    this->passengerNum = passengerNum;
    this->state = PassengerState::Away;
    this->floorNum = floorNum;
    this->elevatorNum = -1; // we don't know initally
    this->destinationFloor = destinationFloor;
    this->direction = dir;

    Passenger::initUI();
}

Passenger::~Passenger() {
    delete ui;
}

void Passenger::initUI() {
    Passenger::updateUI();
}

QString Passenger::getStateString() const {
    switch(this->state){
	case PassengerState::Waiting:
	    return "Waiting";
	case PassengerState::Riding:
	    return "Riding";
	case PassengerState::Arrived:
	    return "Arrived";
	case PassengerState::Away:
	    return "Away";
	default:
	    return "Unknown State";
    }
}

PassengerState Passenger::getState() const {
    return state;
}

bool Passenger::isAway() const {
    return this->state == PassengerState::Away;
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
    button.press();
}

void Passenger::boardElevator(int elevatorNum) {
    this->setFloorNum(-1);
    this->setElevatorNum(elevatorNum);
    this->setState(PassengerState::Riding);
}

void Passenger::exitElevator(int floorNum) {
    this->setElevatorNum(-1);
    this->setFloorNum(floorNum);
    this->setState(PassengerState::Arrived);
}

void Passenger::wait() {
    this->setState(PassengerState::Waiting);
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

void Passenger::setDirection(Direction dir) {
    this->direction = dir;
}

void Passenger::setState(PassengerState state) {
    this->state = state;
}

int Passenger::getPassengerNum() const {
    return this->passengerNum; 
}

int Passenger::getFloorNum() const { 
    return this->floorNum; 
}

int Passenger::getElevatorNum() const {
    return this->elevatorNum;
}

int Passenger::getDestinationFloor() const { 
    return this->destinationFloor; 
}

Direction Passenger::getDirection() const {
    return this->direction;
}

void Passenger::updateUI() {
    ui->passengerLabel->setText(QString("Passenger %1").arg(this->passengerNum + 1));
    ui->stateLabel->setText(this->getStateString());
    ui->currentFloorLabel->setText(QString("Floor %1").arg(this->floorNum + 1));
    ui->currentElevatorLabel->setText(QString("Elevator %1").arg(this->elevatorNum + 1));
}


