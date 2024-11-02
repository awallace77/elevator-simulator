#ifndef PASSENGER_H
#define PASSENGER_H

#include <QDebug>
#include <QString>

//#include <QPainter>
//#include <QPaintEvent>

#include "SimulationComponent.h"
#include "PassengerState.h"
#include "Button.h"

namespace Ui {
class Passenger;
}

class Passenger : public SimulationComponent {
    Q_OBJECT

public:
    explicit Passenger(int, int, int, QWidget *parent = nullptr);
    ~Passenger();
    bool isWaiting() const;
    bool isRiding() const;
    bool hasArrived() const;
    QString getState() const;

    void pressButton(Button&);
    void boardElevator(int);
    void exitElevator(int);

    void setPassengerNum(int);
    void setElevatorNum(int);
    void setFloorNum(int);
    void setDestinationFloor(int);

    virtual void updateUI() override;
    virtual void initUI() override;

private:
    Ui::Passenger *ui;
    int passengerNum;
    PassengerState state;
    int floorNum;
    int elevatorNum;
    int destinationFloor;

    /*
    void paintEvent(QPaintEvent *event) override {
	qInfo() << QString("Painting for passenger: %1").arg(this->passengerNum);

	Q_UNUSED(event);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing); // Smooth edges

	painter.drawEllipse(80, 20, 40, 40); // head (x, y, width, height)
	painter.drawLine(100, 60, 100, 180); // body
	painter.drawLine(100, 80, 50, 120);  // left arm
	painter.drawLine(100, 80, 150, 120); // right arm
	painter.drawLine(100, 180, 50, 240);  // left leg
	painter.drawLine(100, 180, 150, 240); // right leg
    }
    */

};

#endif // PASSENGER_H
