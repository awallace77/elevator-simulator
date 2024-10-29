#include "Floor.h"
#include "ui_Floor.h"
#include <QDebug>

Floor::Floor(int floorNum, QWidget *parent) :
    SimulationComponent(parent),
    ui(new Ui::Floor)
{
    ui->setupUi(this);
    this->floorNum = floorNum;
    this->upButton = new FloorButton(*this, Direction::Up, this);
    this->downButton = new FloorButton(*this, Direction::Down, this);

    this->initUI();
}

Floor::~Floor() {
    delete ui;
    delete upButton;
    delete downButton;
}

void Floor::inform(Direction direction) {
    // TODO: send this information to the ECS
    qInfo() << "Informed about direction";
}

void Floor::serviced(Direction direction) {
    qInfo() << "Informed about serviced";
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

void Floor::updateUI() {
    ui->label->setText(QString("Floor %1").arg(this->floorNum));
    this->upButton->updateUI();
    this->downButton->updateUI();
}

void Floor::initUI() {
    this->updateUI();
    ui->buttonLayout->addWidget(upButton);
    ui->buttonLayout->addWidget(downButton);
}
