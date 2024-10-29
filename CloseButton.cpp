#include "CloseButton.h"
#include "ui_CloseButton.h"

CloseButton::CloseButton(Elevator &elevator, QWidget *parent) :
    Button(parent),
    ui(new Ui::CloseButton),
    elevator(elevator)
{
    ui->setupUi(this);
    this->initUI();
}

CloseButton::~CloseButton() {
    delete ui;
}

void CloseButton::press() {
    this->on();
    this->elevator.close();
}

void CloseButton::updateUI() {
    ui->pushButton->setText(QString("Close Button: %1").arg(this->getState()));
}

void CloseButton::initUI() {
    this->updateUI();
}

