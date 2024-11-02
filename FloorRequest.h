#ifndef FLOOR_REQUEST_H
#define FLOOR_REQUEST_H

#include "Direction.h"
class FloorRequest {

    public:
	FloorRequest(int, Direction);
	//~FloorRequest();
	int getOrigin() const;
	Direction getDirection() const;

	void setOrigin(int);
	void setDirection(Direction);

    private:
	int origin;
	Direction direction;
};

#endif
