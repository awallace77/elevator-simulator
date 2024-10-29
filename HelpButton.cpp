#include "HelpButton.h"
#include "ui_HelpButton.h"

HelpButton::HelpButton(Elevator &elevator, QWidget *parent) :
    Button (parent),
    ui(new Ui::HelpButton),
    elevator(elevator)
{
    ui->setupUi(this);
    this->initUI();

}

HelpButton::~HelpButton() {
    delete ui;
}

void HelpButton::press() {
    this->on();
    this->elevator.help();
}

void HelpButton::updateUI() {
    ui->pushButton->setText(QString("Help Button: %1").arg(this->getState()));
}

void HelpButton::initUI() {
    this->updateUI();
}
