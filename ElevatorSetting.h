#ifndef ELEVATORSETTING_H
#define ELEVATORSETTING_H

#include <QWidget>

namespace Ui {
class ElevatorSetting;
}

class ElevatorSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ElevatorSetting(QWidget *parent = nullptr, int = 0);
    ~ElevatorSetting();

    int getElevatorNum() const;
    bool getOverloaded() const;
    int getOverloadedTime() const;
    bool getObstacle() const;
    int getObstacleTime() const;
    int getCapacity() const;

private slots:
    void on_overloadedCheckBox_stateChanged(int arg1);
    void on_overloadedSpinBox_valueChanged(int arg1);
    void on_obstacleCheckBox_stateChanged(int arg1);
    void on_obstacleSpinBox_valueChanged(int arg1);
    void on_capacitySpinBox_valueChanged(int arg1);

private:
    Ui::ElevatorSetting *ui;
    int elevatorNum;
    bool overloaded;
    int overloadedTime;
    bool obstacle;
    int obstacleTime;
    int capacity;

    void initUI();
};

#endif // ELEVATORSETTING_H
