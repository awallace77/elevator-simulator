#include "Sensor.h"

Sensor::Sensor(Elevator &el) : elevator(el) { }
Sensor::~Sensor() { }

void Sensor::detectMe(int floorNum) {
    elevator.newFloor(floorNum);
}
