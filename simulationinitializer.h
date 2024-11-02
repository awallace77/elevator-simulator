#ifndef SIMULATIONINITIALIZER_H
#define SIMULATIONINITIALIZER_H

#include "Elevator.h"
#include "Floor.h"
#include "Passenger.h"
#include <vector>
#include <QObject>
#include <QDebug>

class SimulationInitializer : public QObject {
    Q_OBJECT

    public:
        explicit SimulationInitializer(QObject* parent = nullptr);

    public slots:
        void updatePassengers(int);

    private:
        void addPassenger();
        void removePassenger();
        void addFloor();
        void removeFloor();
        void addElevator();
        void removeElevator();

    private:
        std::vector<Elevator*> elevators;
        std::vector<Floor*> floors;
        std::vector<Passenger*> passengers;

};

#endif // SIMULATIONINITIALIZER_H
