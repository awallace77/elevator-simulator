#ifndef PASSENGERSETTING_H
#define PASSENGERSETTING_H

#include <QWidget>
#include <QString>
#include "Direction.h"

namespace Ui {
class PassengerSetting;
}

class PassengerSetting : public QWidget
{
    Q_OBJECT

public:
    explicit PassengerSetting(QWidget *parent = nullptr, int=0);
    ~PassengerSetting();
    QString toString();

    int getPassengerNum() const;
    int getTimeFloorPressed() const;
    int getStartFloor() const;
    Direction getDirection() const;
    int getDestinationFloor() const;
    bool getHelpPressed() const;
    int getTimeHelpPressed() const;
    bool getOpenDoorPressed() const;
    int getTimeOpenDoorPressed() const;
    bool getCloseDoorPressed() const;
    int getTimeCloseDoorPressed() const;

    void setTimeFloorPressed(int);
    void setTimeHelpPressed(int);
    void setTimeOpenDoorPressed(int);
    void setTimeCloseDoorPressed(int);

private slots:
    void on_timeFloorButtonPressedSpinBox_valueChanged(int arg1);
    void on_startFloorSpinBox_valueChanged(int arg1);
    void on_directionComboBox_currentTextChanged(const QString &arg1);
    void on_destinationFloorSpinBox_valueChanged(int arg1);
    void on_helpCheckBox_stateChanged(int arg1);
    void on_helpSpinBox_valueChanged(int arg1);
    void on_openDoorCheckBox_stateChanged(int arg1);
    void on_openDoorSpinBox_valueChanged(int arg1);
    void on_closeDoorCheckBox_stateChanged(int arg1);
    void on_closeDoorSpinBox_valueChanged(int arg1);

private:
    Ui::PassengerSetting *ui;
    int passengerNum;
    int timeFloorPressed;
    int startFloor;
    Direction direction;
    int destinationFloor;
    bool helpPressed;
    int timeHelpPressed;
    bool openDoorPressed;
    int timeOpenDoorPressed;
    bool closeDoorPressed;
    int timeCloseDoorPressed;

    void initUI();
};

#endif // PASSENGERSETTING_H
