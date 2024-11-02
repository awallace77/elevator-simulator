#include "FloorRequest.h"

FloorRequest::FloorRequest(int floor, Direction direction) : origin(floor), direction(direction) { }

int FloorRequest::getOrigin() const { return origin; }
Direction FloorRequest::getDirection() const { return direction; }

void FloorRequest::setOrigin(int origin) { this->origin = origin; }
void FloorRequest::setDirection(Direction dir) { this->direction = dir; }

