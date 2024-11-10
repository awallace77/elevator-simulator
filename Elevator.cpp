#include "Elevator.h"
#include "ui_Elevator.h"
#include <QDebug>

Elevator::Elevator(int num, int floor, int capacity, int numFloors, ElevatorControl *ecs, QWidget *parent)
    : SimulationComponent(parent), ui(new Ui::Elevator) {
    ui->setupUi(this);
    this->floor = floor;
    this->direction = Direction::None;
    this->elevatorNumber = num;
    this->capacity = capacity;
    this->name = QString("Elevator %1").arg(this->elevatorNumber + 1);
    this->state = ElevatorState::Idle;
    this->numPassengers = 0;
    this->hasEmergency = false;

    // Objects that belong to the elevator
    this->sensor = new Sensor(*this); // non UI 
    this->door = new Door(this, DoorState::Closed);
    this->display = new Display(this, "Display says: Idle");
    this->speaker = new Speaker(this);
    this->openButton = new OpenButton(*this, this);
    this->closeButton = new CloseButton (*this, this);
    this->helpButton = new HelpButton (*this, this);

    // Destination button for each floor
    for(int i = 0; i < numFloors; i++) {
        this->destinationButtons.push_back(new DestinationButton(*this, i, this));
    }

    //this->ecs = ecs;
    Elevator::initUI();
    this->ecs = ecs;
}

Elevator::~Elevator() {
    delete ui;
    delete door;
    delete display;
    delete speaker;
    delete openButton;
    delete closeButton;
    delete helpButton;
    for(auto &btn : destinationButtons) delete btn;
}

void Elevator::initUI() {
    ui->elevatorLabel->setText(this->getName());
    ui->elevatorFloorLabel->setText(QString("Floor %1").arg(this->getFloorNum() + 1));
    ui->elevatorStateLabel->setText(QString("State: %1").arg(this->getStateString()));
    ui->elevatorCapactiyLabel->setText(QString("Capacity: %1").arg(this->getCapacity()));
    ui->elevatorDirectionLabel->setText(QString("Direction: %1").arg(this->getDirectionString()));
    ui->elevatorPassengersLabel->setText(QString("Passengers: %1").arg(this->getNumPassengers()));
    ui->elevator->insertWidget(0, door);

    ui->elevatorIndoorLayout->addWidget(this->display, 0, 0);
    ui->elevatorIndoorLayout->addWidget(this->speaker, 1, 0);
    ui->elevatorIndoorLayout->addWidget(this->openButton, 2, 0);
    ui->elevatorIndoorLayout->addWidget(this->closeButton, 2, 1);
    ui->elevatorIndoorLayout->addWidget(this->helpButton, 3, 0);

    int row = 3;
    int col = 1;
    int rowCount = 1;
    for(auto &btn : destinationButtons){

	if(rowCount == 2){
	    rowCount = 0;
	    ++row;
	}

	ui->elevatorIndoorLayout->addWidget(btn, row, col);
	++rowCount;
	col = col == 1 ? 0 : 1;
	
    }
}

void Elevator::updateUI() {
    ui->elevatorFloorLabel->setText(QString("Floor: %1").arg(this->getFloorNum() + 1));
    ui->elevatorStateLabel->setText(QString("State: %1").arg(this->getStateString()));
    ui->elevatorDirectionLabel->setText(QString("Direction: %1").arg(this->getDirectionString()));
    ui->elevatorPassengersLabel->setText(QString("Passengers: %1").arg(this->getNumPassengers()));

    this->door->updateUI();
    this->openButton->updateUI();
    this->closeButton->updateUI();
    this->helpButton->updateUI();
    this->display->updateUI();
    this->speaker->updateUI();
    for(auto &btn : destinationButtons) btn->updateUI();
}

void Elevator::start(Direction dir){
    this->setDirection(dir);
    this->close();
    this->setState(ElevatorState::Moving);
}

void Elevator::move() {
    this->setState(ElevatorState::Moving);
    Direction dir = this->getDirection();
    int newFloor = this->getFloorNum();

    if(dir != Direction::Up && dir != Direction::Down) return;
    if(dir == Direction::Up) newFloor = newFloor + 1;
    else if(dir == Direction::Down) newFloor = newFloor - 1;

    this->sensor->detectMe(newFloor);
}

void Elevator::newFloor(int num) {
    this->setFloor(num);
    this->display->setMessage(QString("Display says: Floor %1").arg(num + 1));
}

void Elevator::stop() {
    this->setState(ElevatorState::Stopped);
    this->open();
    if(this->isEmergency()){
        this->speaker->soundEmergency();
        this->display->showEmergency();
    }
}

void Elevator::rest() {
    this->setState(ElevatorState::Idle);
    this->setDirection(Direction::None);
}

void Elevator::obstacle() {
    this->setState(ElevatorState::Safety);
    this->open();
    this->speaker->soundWarning();
    this->display->showObstacle();
}

void Elevator::overloaded() {
    this->setState(ElevatorState::Safety);
    this->open();
    this->speaker->soundWarning();
    this->display->showOverloaded();
}

void Elevator::openRequest() {
    this->setState(ElevatorState::Safety);
    this->open();
    this->display->setMessage(QString("Display says: Open Door Requested"));
}

void Elevator::closeRequest() {
    this->close();
    this->display->setMessage(QString("Display says: Close door requested"));
}

void Elevator::emergency() {
    this->setState(ElevatorState::Emergency);
    this->setEmergency(true);
}

void Elevator::inform(int dest) {
    this->ecs->carRequest(getElevatorNum(), dest);
}

void Elevator::open() {
    this->speaker->soundBell();
    this->door->openDoor();
}

void Elevator::close() {
    this->speaker->soundBell();
    this->door->closeDoor();
    this->getCloseButton()->off();
    this->getOpenButton()->off();
}

void Elevator::help() {
    this->setState(ElevatorState::Safety);
    this->ecs->helpRequest(getElevatorNum());
}

void Elevator::connect(QString help) {
    this->speaker->setMessage(help);
}

void Elevator::addPassenger() {
    ++this->numPassengers;
}

void Elevator::removePassenger() {
    this->numPassengers = (this->numPassengers - 1) >= 0 ? this->numPassengers - 1 : 0;
}

QString Elevator::toString() const {
    return QString("Name: %1\nFloor: %2\nState: %3\nCapacity: %4")
            .arg(name)
            .arg(QString::number(floor + 1)) // Assuming floor is an integer
            .arg(this->getStateString()) // Make sure state is a QString
            .arg(QString::number(capacity)); // Assuming capacity is an integer
}

ElevatorState Elevator::getState() const {
    return state;
}

QString Elevator::getStateString() const {
    switch(this->state){
	case ElevatorState::Idle:
	    return "Idle";
	case ElevatorState::Moving:
	    return "Moving";
	case ElevatorState::Stopped:
	    return "Stopped";
	case ElevatorState::OutOfService:
	    return "Out of service";
	case ElevatorState::Safety:
	    return "Safety";
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

int Elevator::getFloorNum() const {
    return floor;
}

int Elevator::getElevatorNum() const {
    return elevatorNumber;
}

int Elevator::getCapacity() const {
    return capacity;
}

int Elevator::getNumPassengers() const {
    return this->numPassengers;
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

Button* Elevator::getDestinationButton(int num) const {
    for(auto &btn : destinationButtons){
        if(btn->getNumber() == num) return btn;
    }
    return nullptr;
}

bool Elevator::isSafety() const {
    return (state == ElevatorState::Safety);
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
    return this->hasEmergency;
}

bool Elevator::isOutOfService() const {
    return (state == ElevatorState::OutOfService);
}

void Elevator::setState(ElevatorState state){
    this->state = state;
}

void Elevator::setFloor(int floor){
    this->floor = floor;
}

void Elevator::setElevatorNumber(int num){
    this->elevatorNumber = num;
}

void Elevator::setCapacity(int num){
    this->capacity = num;
}

void Elevator::setName(QString name){
    this->name = name;
}

void Elevator::setDirection(Direction dir){
    this->direction = dir;
}

void Elevator::setNumPassengers(int num) {
    this->numPassengers = num;
}

void Elevator::setEmergency(bool emerg) {
    this->hasEmergency = emerg;
}
