#include "DestinationButton.h"
#include "ui_DestinationButton.h"

DestinationButton::DestinationButton(Elevator &elevator, int destNumber, QWidget *parent) :
    Button(parent),
    ui(new Ui::DestinationButton),
    elevator(elevator)
{
    ui->setupUi(this);
    this->number = destNumber;
    DestinationButton::initUI();
}

DestinationButton::~DestinationButton() {
    delete ui;
}

void DestinationButton::press() {
    this->on();
    this->elevator.inform(this->getNumber());
}

void DestinationButton::initUI() {
    DestinationButton::updateUI();
}

void DestinationButton::updateUI() {
    ui->pushButton->setText(QString("Destination Button %1: %2").arg(this->getNumber() + 1).arg(this->getState()));
}

void DestinationButton::setNumber(int num) {
    this->number = num;
}

int DestinationButton::getNumber() const {
    return number;
}
