#include "Floor.h"
#include "ui_Floor.h"
#include <QDebug>

Floor::Floor(int floorNum, ElevatorControl *ecs, QWidget *parent) :
    SimulationComponent(parent),
    ui(new Ui::Floor)
{
    ui->setupUi(this);
    this->floorNum = floorNum;
    this->upButton = new FloorButton(*this, Direction::Up, this);
    this->downButton = new FloorButton(*this, Direction::Down, this);
    this->ecs = ecs;

    Floor::initUI();
}

Floor::~Floor() {
    delete ui;
    delete upButton;
    delete downButton;
}

void Floor::inform(Direction direction) {
    ecs->floorRequest(this->getFloorNum(), direction);
}

void Floor::serviced(Direction direction) {
    switch(direction){
        case Direction::Up:
            this->upButton->off();
            break;
        case Direction::Down:
            this->downButton->off();
            break;
        default:
            // noop
            break;
    }
}

void Floor::setFloorNum(int num) {
    this->floorNum = num;
}

int Floor::getFloorNum() const {
    return this->floorNum;
}

void Floor::updateUI() {
    ui->label->setText(QString("Floor %1").arg(this->floorNum + 1));
    this->upButton->updateUI();
    this->downButton->updateUI();
}

void Floor::initUI() {
    Floor::updateUI();
    ui->buttonLayout->addWidget(upButton);
    ui->buttonLayout->addWidget(downButton);
}

FloorButton* Floor::getFloorUpButton() const {
    return this->upButton;
}

FloorButton* Floor::getFloorDownButton() const {
    return this->downButton;
}

