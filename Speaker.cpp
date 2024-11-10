#include "Speaker.h"
#include "ui_Speaker.h"

Speaker::Speaker(QWidget *parent, QString msg) :
    SimulationComponent(parent),
    ui(new Ui::Speaker) {
    ui->setupUi(this);
    this->setMessage(msg);
    Speaker::initUI();
}

Speaker::~Speaker() {
    delete ui;
}

void Speaker::setMessage(QString msg) {
    this->message = msg;
}

QString Speaker::getMessage() const {
    return this->message;
}

void Speaker::soundBell() {
    this->setMessage("Speaker says: Bing");
}

void Speaker::soundRing() {
    this->setMessage("Speaker says: Ring Ring");
}

void Speaker::soundWarning() {
    this->setMessage("Speaker says: Warning Warning");
}

void Speaker::soundEmergency() {
    this->setMessage("Speaker says: Emergency Emergency");
}

void Speaker::updateUI() {
    ui->label->setText(this->message);
}

void Speaker::initUI() {
    Speaker::updateUI();
}


