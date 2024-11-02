#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

#include "Button.h"
#include "Direction.h"
#include "Floor.h"

class Floor;

namespace Ui {
class FloorButton;
}

class FloorButton : public Button {
    Q_OBJECT

public:
    explicit FloorButton(Floor&, Direction, QWidget *parent = nullptr);
    ~FloorButton();

    virtual void press() override;
    virtual void updateUI() override;
    virtual void initUI() override;


    void setDirection(Direction);
    QString getDirectionString() const;
    Direction getDirection() const;

private:
    Ui::FloorButton *ui;
    Direction direction;
    Floor &floor;
};

#endif // FLOORBUTTON_H
