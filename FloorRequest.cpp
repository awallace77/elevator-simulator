#include "FloorRequest.h"

FloorRequest::FloorRequest(int floor, Direction direction) : floor(floor), direction(direction) { }
FloorRequest::~FloorRequest() { }

int FloorRequest::getFloorNum() const { return floor; }
Direction FloorRequest::getDirection() const { return direction; }

void FloorRequest::setFloorNum(int origin) { this->floor = origin; }
void FloorRequest::setDirection(Direction dir) { this->direction = dir; }
