#ifndef DOOR_H
#define DOOR_H

#include <QWidget>
#include <QString>
#include "DoorState.h"
#include "SimulationComponent.h"

namespace Ui {
class Door;
}

class Door : public SimulationComponent {
    Q_OBJECT

    public:
	explicit Door(QWidget *parent = nullptr, DoorState state = DoorState::Closed);
	~Door();
	bool isOpen() const;
	QString getState() const;
	virtual void updateUI() override;

    public slots: 
	void openDoor();
	void closeDoor();

    private:
	Ui::Door *ui;
	DoorState state;
	virtual void initUI() override;
};

#endif // DOOR_H
