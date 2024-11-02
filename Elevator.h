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
#include "Button.h"
#include "ElevatorControl.h"
#include "AllocationStrategy.h"

class OpenButton;
class CloseButton;
class HelpButton;
class ElevatorControl;
class AllocationStrategy;


namespace Ui {
class Elevator;
}

class Elevator : public SimulationComponent {
    Q_OBJECT

    public:
    explicit Elevator(int, int, int, ElevatorControl*, QWidget *parent = nullptr);
	~Elevator();
    virtual void updateUI() override;
    virtual void initUI() override;


	void open();
	void close();
	void help();
	void start(Direction);
	void move(); // moves in the direction
	void stop();

	bool isIdle() const;
	bool isMoving() const;
	bool isStopped() const;
	bool isEmergency() const;
	bool isOutOfService() const;

	QString toString() const;

	QString getStateString() const;
	ElevatorState getState() const;
	int getFloor() const;
	int getElevatorNumber() const;
	int getCapacity() const;
	QString getName() const;
	Direction getDirection() const;
	QString getDirectionString() const;

	void setState(ElevatorState);
	void setFloor(int);
	void setElevatorNumber(int);
	void setCapacity(int);
	void setName(QString);
	void setDirection(Direction);
	void setIdle();

	Button* getOpenButton() const;
	Button* getCloseButton() const;
	Button* getHelpButton() const;

    signals:
//	void carRequest(int);
//	QString broadcastEmerg();

    public slots:
/*	void newFloor(int);
	void start(QString);
	void stop();
	void obstacle();
	void overloaded();
	void turnOnBackupPower();
	void shouldDispatchWarning();
	*/

    private:
	Ui::Elevator *ui;
	int floor;
	int elevatorNumber;
	int capacity;
	QString name;
	Direction direction;
	ElevatorState state;

	Door *door;
	Display *display;
	Speaker *speaker;
	Button *openButton;
	Button *closeButton;
	Button *helpButton;

	ElevatorControl *ecs;

};

#endif // ELEVATOR_H

