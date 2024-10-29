#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->numElevators = 0;
    this->numPassengers = 0;
    this->numFloors = 0;
    this->buildingSetting = new BuildingSetting();
    this->simulation = new Simulation();
    this->updateUI();
}

MainWindow::~MainWindow() {
    delete ui;
    for(auto &pSetting : this->passengerSettings) delete pSetting;
    for(auto &eSetting : this->elevatorSettings) delete eSetting;
    delete this->buildingSetting;
    delete this->simulation;
}

// Slots
void MainWindow::on_elevatorSpinBox_valueChanged(int num) {
    this->numElevators = num;
}

void MainWindow::on_passengerSpinBox_valueChanged(int num) {
    this->numPassengers = num;
}

void MainWindow::on_updateSimulationButton_clicked() {
    this->updateUI();
}

void MainWindow::updateUI() {
    this->updatePassengerMenus();
    this->updateElevatorMenus();
}

// Elevator Settings
void MainWindow::updateElevatorMenus() {
    this->clearLayout(ui->elevatorSettingsLayout);
    this->elevatorSettings.clear();
    for(int i = 0; i < this->numElevators; i++) {
	this->addElevatorMenu(i);
    }

    for(auto &setting : this->elevatorSettings) {
       ui->elevatorSettingsLayout->addWidget(setting);
    };
}

void MainWindow::addElevatorMenu(int num)  {
    ElevatorSetting* setting = new ElevatorSetting(this, num);
    this->elevatorSettings.push_back(setting);
}

// Passenger Settings
void MainWindow::updatePassengerMenus() {
    this->clearLayout(ui->passengerSettingsLayout);
    this->passengerSettings.clear();
    for(int i = 0; i < this->numPassengers; i++) {
	this->addPassengerMenu(i);
    }

    for(auto &setting: this->passengerSettings) {
	ui->passengerSettingsLayout->addWidget(setting);
    }
}

void MainWindow::addPassengerMenu(int num){
    PassengerSetting *setting = new PassengerSetting(this, num);
    this->passengerSettings.push_back(setting);
}

// Floors
void MainWindow::on_floorSpinBox_valueChanged(int num) {
    this->numFloors = num;
}

// Building
void MainWindow::on_fireCheckBox_stateChanged(int checked) {
    this->buildingSetting->setFire(checked == Qt::Unchecked ? false : true);
}

void MainWindow::on_fireSpinBox_valueChanged(int time) {
    this->buildingSetting->setFireTime(time);
}

void MainWindow::on_powerOutageCheckBox_stateChanged(int checked) {
    this->buildingSetting->setPowerOutage(checked == Qt::Unchecked ? false : true);
}

void MainWindow::on_powerOutageSpinBox_valueChanged(int time) {
    this->buildingSetting->setPowerOutageTime(time);
}

void MainWindow::on_startSimulationButton_clicked() {
    ui->updateSimulationButton->setDisabled(true);
    this->simulation->show();
    this->simulation->start(
	    elevatorSettings, 
	    passengerSettings, 
	    buildingSetting, 
	    numElevators, 
	    numPassengers, 
	    numFloors
    );
}

void MainWindow::clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}
