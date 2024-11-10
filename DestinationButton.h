#ifndef DESTINATIONBUTTON_H
#define DESTINATIONBUTTON_H

#include <QWidget>
#include "Elevator.h"
class Elevator;

namespace Ui {
class DestinationButton;
}

class DestinationButton : public Button {
    Q_OBJECT

public:
    explicit DestinationButton(Elevator&, int, QWidget *parent = nullptr);
    ~DestinationButton();

    virtual void press() override;
    virtual void updateUI() override;
    virtual void initUI() override;

    void setNumber(int);
    int getNumber() const;

private:
    Ui::DestinationButton *ui;
    Elevator &elevator;
    int number;
};

#endif // DESTINATIONBUTTON_H
