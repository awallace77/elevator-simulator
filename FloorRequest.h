#ifndef FLOOR_REQUEST_H
#define FLOOR_REQUEST_H

#include "Direction.h"
class FloorRequest {

    public:
	FloorRequest(int, Direction);
	//~FloorRequest();
	int getFloor() const;
	Direction getDirection() const;

	void setFloor(int);
	void setDirection(Direction);

    private:
	int floor;
	Direction direction;
};

#endif
