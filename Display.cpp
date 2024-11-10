#include "Display.h"
#include "ui_Display.h"

Display::Display(QWidget *parent, QString msg) :
    SimulationComponent(parent),
    ui(new Ui::Display) {
    ui->setupUi(this);
    this->setMessage(msg);
    Display::initUI();
}

Display::~Display() {
    delete ui;
}

void Display::setMessage(QString msg) {
    this->message = msg;
}

QString Display::getMessage() const {
    return this->message;
}

void Display::showOverloaded() {
    this->setMessage("Display says: Warning. Elevator overloaded.");
}

void Display::showObstacle() {
    this->setMessage("Display says: Warning. Obstacle detected.");
}

void Display::showEmergency() {
    this->setMessage("Display says: Emergency. Please disembark on the safe floor.");
}

void Display::updateUI() {
    ui->label->setText(this->message);
}

void Display::initUI() {
    Display::updateUI();
}

