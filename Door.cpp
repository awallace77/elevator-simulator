#include "Door.h"
#include "ui_Door.h"

Door::Door(QWidget *parent, DoorState state) : SimulationComponent(parent), ui(new Ui::Door) {
    ui->setupUi(this);
    this->state = state;
    this->closeDoor();
    this->initUI();
}

Door::~Door() {
    delete ui;
}

void Door::updateUI() {
    ui->doorGroupBox->setTitle(this->getState());
}

void Door::initUI() {
    this->updateUI();
}

void Door::openDoor() {
    this->state = DoorState::Open;
}

void Door::closeDoor() {
    this->state = DoorState::Closed;
}

QString Door::getState() const {
    switch(this->state){
	case DoorState::Open:
	    return "Open";
	case DoorState::Closed:
	    return "Closed";
	default:
	    return "Unknown State";
    }
}

bool Door::isOpen() const {
    return (this->state == DoorState::Open);
}


