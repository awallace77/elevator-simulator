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
    this->setMessage("Bing");
}

void Speaker::soundRing() {
    this->setMessage("Ring Ring");
}

void Speaker::updateUI() {
    ui->label->setText(this->message);
}

void Speaker::initUI() {
    Speaker::updateUI();
}


