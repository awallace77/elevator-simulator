#include "ElevatorWindow.h"

ElevatorWindow::ElevatorWindow(QWidget *parent) : QMdiSubWindow(parent) {
    elevator = new Elevator(this);
    this->setWidget(elevator);
}

ElevatorWindow::~ElevatorWindow() {
    elevator->~Elevator();
}

