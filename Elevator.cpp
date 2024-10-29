#include "Elevator.h"
#include "ui_Elevator.h"
#include <QDebug>

Elevator::Elevator(int num, int floor, int capacity, QWidget *parent) 
    : SimulationComponent(parent), ui(new Ui::Elevator) {
    ui->setupUi(this);
    this->floor = floor;
    this->direction = Direction::None;
    this->elevatorNumber = num;
    this->capacity = capacity;
    this->name = QString("Elevator %1").arg(this->elevatorNumber + 1);
    this->state = ElevatorState::Idle;

    // Objects that belong to the elevator
    this->door = new Door(this, DoorState::Closed);
    this->display = new Display(this);
    this->speaker = new Speaker(this);
    this->openButton = new OpenButton(*this, this);
    this->closeButton = new CloseButton (*this, this);
    this->helpButton = new HelpButton (*this, this);

    this->initUI();
}

Elevator::~Elevator() {
    delete ui;
    delete door;
    delete display;
    delete speaker;
    delete openButton;
    delete closeButton;
    delete helpButton;
}

void Elevator::initUI() {
    ui->elevatorLabel->setText(this->getName());
    ui->elevatorFloorLabel->setText(QString("Floor %1").arg(this->getFloor()));
    ui->elevatorStateLabel->setText(this->getState());
    ui->elevatorCapactiyLabel->setText(QString("Capacity: %1").arg(this->getCapacity()));
    ui->elevator->insertWidget(0, door);

    ui->elevatorIndoorLayout->addWidget(this->display);
    ui->elevatorIndoorLayout->addWidget(this->speaker);
    ui->elevatorIndoorLayout->addWidget(this->openButton);
    ui->elevatorIndoorLayout->addWidget(this->closeButton);
    ui->elevatorIndoorLayout->addWidget(this->helpButton);
}

void Elevator::updateUI() {

    ui->elevatorDirectionLabel->setText(this->getDirectionString());
    ui->elevatorFloorLabel->setText(QString("Floor: %1").arg(this->getFloor()));
    ui->elevatorStateLabel->setText(this->getState());
    this->door->updateUI();
    this->openButton->updateUI();
    this->closeButton->updateUI();
    this->helpButton->updateUI();
}

void Elevator::open() {
    // TODO: Send open request to the ECS
    qInfo() << QString("Open request on elevator %1 recieved").arg(getElevatorNumber());
}

void Elevator::close() {
    // TODO: Send close request to the ECS
    qInfo() << QString("Close request on elevator %1 recieved").arg(getElevatorNumber());
}

void Elevator::help() {
    // TODO: Send help request to the ECS
    qInfo() << QString("Help request on elevator %1 recieved").arg(getElevatorNumber());
}

QString Elevator::toString() const {
    return QString("Name: %1\nFloor: %2\nState: %3\nCapacity: %4")
            .arg(name)
            .arg(QString::number(floor)) // Assuming floor is an integer
            .arg(this->getState()) // Make sure state is a QString
            .arg(QString::number(capacity)); // Assuming capacity is an integer
}

QString Elevator::getState() const {
    switch(this->state){
	case ElevatorState::Idle:
	    return "Idle";
	case ElevatorState::Moving:
	    return "Moving";
	case ElevatorState::Stopped:
	    return "Stopped";
	case ElevatorState::OutOfService:
	    return "Out of service";
	case ElevatorState::Emergency:
	    return "Emergency";
	default:
	    return "Unknown state";
    }
}

Direction Elevator::getDirection() const {
    return this->direction;
}

QString Elevator::getDirectionString() const {
    switch(this->direction){
	case Direction::Up:
	    return "Up";
	case Direction::Down:
	    return "Down";
	case Direction::None:
	    return "None";
	default:
	    return "Unknown Direction";
    }
}

int Elevator::getFloor() const {
    return floor;
}

int Elevator::getElevatorNumber() const {
    return elevatorNumber;
}

int Elevator::getCapacity() const {
    return capacity;
}


QString Elevator::getName() const {
    return name;
}

Button* Elevator::getOpenButton() const {
    return openButton;
}

Button* Elevator::getCloseButton() const {
    return closeButton;
}

Button* Elevator::getHelpButton() const {
    return helpButton;
}

bool Elevator::isIdle() const {
    return (state == ElevatorState::Idle);
}

bool Elevator::isMoving() const {
    return (state == ElevatorState::Moving);
}

bool Elevator::isStopped() const {
    return (state == ElevatorState::Stopped);
}

bool Elevator::isEmergency() const {
    return (state == ElevatorState::Emergency);
}

bool Elevator::isOutOfService() const {
    return (state == ElevatorState::OutOfService);
}
