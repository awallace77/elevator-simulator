#ifndef PASSENGER_H
#define PASSENGER_H

#include <QDebug>
#include <QString>

#include "SimulationComponent.h"
#include "PassengerState.h"
#include "Button.h"
#include "Direction.h"

namespace Ui {
class Passenger;
}

class Passenger : public SimulationComponent {
    Q_OBJECT

public:
    explicit Passenger(int, int, int, Direction, QWidget *parent = nullptr);
    ~Passenger();
    bool isAway() const;
    bool isWaiting() const;
    bool isRiding() const;
    bool hasArrived() const;
    QString getStateString() const;

    void pressButton(Button&);
    void boardElevator(int);
    void exitElevator(int);
    void wait();

    void setPassengerNum(int);
    void setElevatorNum(int);
    void setFloorNum(int);
    void setDestinationFloor(int);
    void setState(PassengerState);
    void setDirection(Direction);

    PassengerState getState() const;
    int getPassengerNum() const;
    int getElevatorNum() const;
    int getFloorNum() const;
    int getDestinationFloor() const;
    Direction getDirection() const;

    virtual void updateUI() override;
    virtual void initUI() override;

private:
    Ui::Passenger *ui;
    int passengerNum;
    PassengerState state;
    int floorNum;
    int elevatorNum;
    int destinationFloor;
    Direction direction;

};

#endif // PASSENGER_H
