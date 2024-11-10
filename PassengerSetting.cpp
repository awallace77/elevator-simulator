#include "PassengerSetting.h"
#include "ui_PassengerSetting.h"

PassengerSetting::PassengerSetting(QWidget *parent, int num) :
    QWidget(parent),
    ui(new Ui::PassengerSetting)
{
    ui->setupUi(this);

    this->passengerNum = num;
    this->timeFloorPressed = 0;
    this->startFloor = 0;
    this->direction = Direction::None;
    this->destinationFloor = 0;
    this->helpPressed = false;
    this->timeHelpPressed = 0;
    this->openDoorPressed = false;
    this->timeOpenDoorPressed = 0;
    this->closeDoorPressed = false;
    this->timeCloseDoorPressed = 0;

    this->initUI();
}

PassengerSetting::~PassengerSetting() {
    delete ui;
}

void PassengerSetting::on_timeFloorButtonPressedSpinBox_valueChanged(int time) { 
    this->timeFloorPressed = time; 
}

void PassengerSetting::on_startFloorSpinBox_valueChanged(int start) {
    this->startFloor = start;
}

void PassengerSetting::on_directionComboBox_currentTextChanged(const QString &direction) {
    if(direction == "Up") this->direction = Direction::Up;
    else if(direction == "Down") this->direction = Direction::Down;
    else this->direction = Direction::None;
}

void PassengerSetting::on_destinationFloorSpinBox_valueChanged(int dest) {
    this->destinationFloor = dest;
}

void PassengerSetting::on_helpCheckBox_stateChanged(int pressed) {
    this->helpPressed = (pressed == Qt::Unchecked ? false : true);
}

void PassengerSetting::on_helpSpinBox_valueChanged(int time) {
    this->timeHelpPressed = time;
}

void PassengerSetting::on_openDoorCheckBox_stateChanged(int pressed) {
    this->openDoorPressed = (pressed == Qt::Unchecked ? false : true);
}


void PassengerSetting::on_openDoorSpinBox_valueChanged(int time) {
    this->timeOpenDoorPressed = time;
}


void PassengerSetting::on_closeDoorCheckBox_stateChanged(int pressed) {
    this->closeDoorPressed = (pressed == Qt::Unchecked ? false : true);
}


void PassengerSetting::on_closeDoorSpinBox_valueChanged(int time) {
    this->timeCloseDoorPressed = time;

}

void PassengerSetting::initUI() {
    ui->directionComboBox->addItem("Up");
    ui->directionComboBox->addItem("Down");
    ui->passengerSettingsLabel->setText(QString("Passenger %1").arg(QString::number(this->passengerNum + 1)));
}

QString PassengerSetting::toString() {

    QString output = QString("Passenger %1\n"
                             "Time floor button pressed: %2\n"
                             "Start floor: %3\n"
                             "Direction: %4\n"
                             "Destination floor: %5\n"
                             "Help button pressed: %6\n"
                             "Time help button pressed: %7\n"
                             "Open door button pressed: %8\n"
                             "Time open door button pressed: %9\n"
                             "Close door button pressed: %10\n"
                             "Time close door button pressed: %11")
        .arg(passengerNum)
        .arg(timeFloorPressed)
        .arg(startFloor)
        .arg("direction")
        .arg(destinationFloor)
        .arg(helpPressed)
        .arg(timeHelpPressed)
        .arg(openDoorPressed)
        .arg(timeOpenDoorPressed)
        .arg(closeDoorPressed)
        .arg(timeCloseDoorPressed);

    return output;
}

// getters
int PassengerSetting::getPassengerNum() const { return passengerNum; }
int PassengerSetting::getTimeFloorPressed() const { return timeFloorPressed; }
int PassengerSetting::getStartFloor() const { return startFloor; }
Direction PassengerSetting::getDirection() const{ return direction; }
int PassengerSetting::getDestinationFloor() const { return destinationFloor; }
bool PassengerSetting::getHelpPressed() const { return helpPressed; }
int PassengerSetting::getTimeHelpPressed() const { return timeHelpPressed; }
bool PassengerSetting::getOpenDoorPressed() const { return openDoorPressed; }
int PassengerSetting::getTimeOpenDoorPressed() const { return timeOpenDoorPressed; }
bool PassengerSetting::getCloseDoorPressed() const { return closeDoorPressed; }
int PassengerSetting::getTimeCloseDoorPressed() const { return timeCloseDoorPressed; }

// setters
void PassengerSetting::setTimeFloorPressed(int time) { this->timeFloorPressed = time; }
void PassengerSetting::setTimeHelpPressed(int time) { this->timeHelpPressed = time; }
void PassengerSetting::setTimeOpenDoorPressed(int time) { this->timeOpenDoorPressed = time; }
void PassengerSetting::setTimeCloseDoorPressed(int time) { this->timeCloseDoorPressed = time; }

