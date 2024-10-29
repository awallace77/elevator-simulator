#ifndef FLOOR_H
#define FLOOR_H

#include "SimulationComponent.h"
#include "Direction.h"
#include "FloorButton.h"

class FloorButton;

namespace Ui {
class Floor;
}

class Floor : public SimulationComponent {
    Q_OBJECT

public:
    explicit Floor(int, QWidget *parent = nullptr);
    ~Floor();
    void inform(Direction);
    void serviced(Direction);

    virtual void updateUI() override;
    void setFloorNum(int);

private:
    Ui::Floor *ui;
    int floorNum;
    FloorButton *upButton;
    FloorButton *downButton;
    virtual void initUI() override;
};

#endif // FLOOR_H
