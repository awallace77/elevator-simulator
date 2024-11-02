#include "ElevatorSetting.h"
#include "ui_ElevatorSetting.h"

ElevatorSetting::ElevatorSetting(QWidget *parent, int num) :
    QWidget(parent),
    ui(new Ui::ElevatorSetting) {
    ui->setupUi(this);

    this->elevatorNum = num;
    this->overloaded = false;
    this->overloadedTime = 0;
    this->obstacle = false;
    this->obstacleTime = 0;
    this->capacity = 0;
    this->initUI();
}

ElevatorSetting::~ElevatorSetting() {
    delete ui;
}

void ElevatorSetting::on_overloadedCheckBox_stateChanged(int num) {
    this->overloaded = (num == Qt::Unchecked ? false : true);
}

void ElevatorSetting::on_overloadedSpinBox_valueChanged(int num) {
    this->overloadedTime = num;
}

void ElevatorSetting::on_obstacleCheckBox_stateChanged(int num) {
    this->obstacle = (num == Qt::Unchecked ? false : true);
}

void ElevatorSetting::on_obstacleSpinBox_valueChanged(int num) {
    this->obstacleTime = num;
}

void ElevatorSetting::initUI() {
    ui->elevatorLabel->setText(QString("Elevator %1").arg(this->elevatorNum + 1));
}

void ElevatorSetting::on_capacitySpinBox_valueChanged(int num) {
    this->capacity = num;
}

int ElevatorSetting::getElevatorNum() const {
    return elevatorNum;
}

bool ElevatorSetting::getOverloaded() const {
    return overloaded;
}

int ElevatorSetting::getOverloadedTime() const {
    return overloadedTime;
}

bool ElevatorSetting::getObstacle() const {
    return obstacle;
}

int ElevatorSetting::getObstacleTime() const {
    return obstacleTime;
}

int ElevatorSetting::getCapacity() const {
    return capacity;
}

