#include "FloorRequest.h"

FloorRequest::FloorRequest(int floor, Direction direction) : floor(floor), direction(direction) { }

int FloorRequest::getFloor() const { return floor; }
Direction FloorRequest::getDirection() const { return direction; }

void FloorRequest::setFloor(int origin) { this->floor = origin; }
void FloorRequest::setDirection(Direction dir) { this->direction = dir; }

