#ifndef FLOOR_H
#define FLOOR_H

#include "SimulationComponent.h"
#include "Direction.h"
#include "FloorButton.h"
#include "ElevatorControl.h"

class FloorButton;
class ElevatorControl;

namespace Ui {
class Floor;
}

class Floor : public SimulationComponent {
    Q_OBJECT

public:
    explicit Floor(int, ElevatorControl *ecs, QWidget *parent = nullptr);
    ~Floor();
    void inform(Direction);
    void serviced(Direction);

    virtual void updateUI() override;
    virtual void initUI() override;

    void setFloorNum(int);
    int getFloorNum() const;

    FloorButton* getFloorUpButton() const;
    FloorButton* getFloorDownButton() const;

private:
    Ui::Floor *ui;
    int floorNum;
    FloorButton *upButton;
    FloorButton *downButton;
    ElevatorControl *ecs;
};

#endif // FLOOR_H
