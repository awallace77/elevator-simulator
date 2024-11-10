#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QWidget>
#include <QString>
#include "ElevatorState.h"
#include "Door.h"
#include "DoorState.h"
#include "Display.h"
#include "Speaker.h"
#include "SimulationComponent.h"
#include "Direction.h"
#include "OpenButton.h" 
#include "CloseButton.h" 
#include "HelpButton.h" 
#include "DestinationButton.h" 
#include "Button.h"
#include "ElevatorControl.h"
#include "AllocationStrategy.h"
#include "Sensor.h"

class OpenButton;
class CloseButton;
class HelpButton;
class ElevatorControl;
class AllocationStrategy;
class DestinationButton;
class Sensor;


namespace Ui {
class Elevator;
}

class Elevator : public SimulationComponent {
    Q_OBJECT

    public:
        explicit Elevator(int, int, int, int, ElevatorControl*, QWidget *parent = nullptr);
        ~Elevator();
        virtual void updateUI() override;
        virtual void initUI() override;

        void open();
        void close();
        void openRequest();
        void closeRequest();
        void help();
        void start(Direction);
        void move();
        void newFloor(int);
        void stop();
        void rest();
        void overloaded();
        void obstacle();
        void emergency();
        void inform(int);
        void connect(QString);

        bool isSafety() const;
        bool isIdle() const;
        bool isMoving() const;
        bool isStopped() const;
        bool isEmergency() const;
        bool isOutOfService() const;

        void addPassenger();
        void removePassenger();

        QString toString() const;
        QString getStateString() const;
        ElevatorState getState() const;
        int getFloorNum() const;
        int getElevatorNum() const;
        int getCapacity() const;
        int getNumPassengers() const;
        QString getName() const;
        Direction getDirection() const;
        QString getDirectionString() const;

        void setState(ElevatorState);
        void setFloor(int);
        void setElevatorNumber(int);
        void setCapacity(int);
        void setNumPassengers(int);
        void setName(QString);
        void setDirection(Direction);
        void setEmergency(bool);
        Button* getOpenButton() const;
        Button* getCloseButton() const;
        Button* getHelpButton() const;
        Button* getDestinationButton(int) const;

    private:
        Ui::Elevator *ui;
        int floor;
        int elevatorNumber;
        int capacity;
        int numPassengers;
        QString name;
        Direction direction;
        ElevatorState state;
        bool hasEmergency;

        Sensor *sensor;
        Door *door;
        Display *display;
        Speaker *speaker;
        Button *openButton;
        Button *closeButton;
        Button *helpButton;
        std::vector<DestinationButton*> destinationButtons;

        ElevatorControl *ecs;

};

#endif // ELEVATOR_H

