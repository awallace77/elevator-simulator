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

void Display::updateUI() {
    ui->label->setText(this->message);
}

void Display::initUI() {
    Display::updateUI();
}

