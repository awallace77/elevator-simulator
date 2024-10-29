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

    void setDirection(Direction);
    QString getDirection() const;

private:
    Ui::FloorButton *ui;
    Direction direction;
    Floor &floor;
    virtual void initUI() override;
};

#endif // FLOORBUTTON_H
