#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include "Button.h" 
#include "Elevator.h"

class Elevator;

namespace Ui {
class CloseButton;
}

class CloseButton : public Button {
    Q_OBJECT

public:
    explicit CloseButton(Elevator&, QWidget *parent = nullptr);
    ~CloseButton();

    virtual void press() override;
    virtual void updateUI() override;

private:
    Ui::CloseButton *ui;
    Elevator &elevator;
    virtual void initUI() override;
};

#endif // CLOSEBUTTON_H
