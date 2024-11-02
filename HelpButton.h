#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include "Button.h" 
#include "Elevator.h"

namespace Ui {
class HelpButton;
}

class HelpButton : public Button  {
    Q_OBJECT

public:
    explicit HelpButton(Elevator&, QWidget *parent = nullptr);
    ~HelpButton();

    virtual void press() override;
    virtual void updateUI() override;
    virtual void initUI() override;

private:
    Ui::HelpButton *ui;
    Elevator &elevator;
};

#endif // HELPBUTTON_H
