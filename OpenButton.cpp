#include "OpenButton.h"
#include "ui_OpenButton.h"

OpenButton::OpenButton(Elevator &elevator, QWidget *parent) :
    Button(parent),
    ui(new Ui::OpenButton),
    elevator(elevator)
{
    ui->setupUi(this);
    this->initUI();
}

OpenButton::~OpenButton() {
    delete ui;
}

void OpenButton::press() {
    this->on();
    this->elevator.open();
}

void OpenButton::updateUI() {
    ui->pushButton->setText(QString("Open Button: %1").arg(this->getState()));
}

void OpenButton::initUI() {
    this->updateUI();
}

