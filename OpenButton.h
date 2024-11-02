#ifndef OPENBUTTON_H
#define OPENBUTTON_H

#include "Button.h"
#include "Elevator.h"
class Elevator;
namespace Ui {
class OpenButton;
}

class OpenButton : public Button {
    Q_OBJECT

public:
    explicit OpenButton(Elevator&, QWidget *parent = nullptr);
    ~OpenButton();
    virtual void press() override;
    virtual void updateUI() override;
    virtual void initUI() override;

private:
    Ui::OpenButton *ui;
    Elevator &elevator;
};

#endif // OPENBUTTON_H
