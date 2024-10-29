#include "FloorButton.h"
#include "ui_FloorButton.h"

FloorButton::FloorButton(Floor &floor, Direction dir, QWidget *parent) :
    Button(parent),
    ui(new Ui::FloorButton),
    direction(dir),
    floor(floor)
{
    ui->setupUi(this);
    this->initUI();
}

FloorButton::~FloorButton() {
    delete ui;
}

void FloorButton::press() {
    this->on();
    this->floor.inform(this->direction);
}

void FloorButton::updateUI() {
    ui->pushButton->setText(QString("%1 Button: %2").arg(this->getDirection()).arg(this->getState()));
}

void FloorButton::setDirection(Direction dir) {
    this->direction = dir;
}

QString FloorButton::getDirection() const {
    switch(this->direction){
        case Direction::Up:
            return "Up";
        case Direction::Down:
            return "Down";
        default:
            return "Unknown Direction";
    }
}

void FloorButton::initUI() {
    this->updateUI();
}

