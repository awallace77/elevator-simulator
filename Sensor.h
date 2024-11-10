#ifndef SENSOR_H
#define SENSOR_H

#include "Elevator.h"

class Sensor {

    public: 
        Sensor(Elevator&);
        ~Sensor();

        void detectMe(int);

    private:
        Elevator &elevator;
};

#endif
