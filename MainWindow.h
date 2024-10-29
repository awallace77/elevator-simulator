#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLayout>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include "ElevatorSetting.h"
#include "PassengerSetting.h"
#include "BuildingSetting.h"
#include "Simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_elevatorSpinBox_valueChanged(int arg1);
    void on_updateSimulationButton_clicked();
    void on_passengerSpinBox_valueChanged(int arg1);
    void on_startSimulationButton_clicked();
    void on_floorSpinBox_valueChanged(int arg1);
    void on_fireCheckBox_stateChanged(int arg1);
    void on_fireSpinBox_valueChanged(int arg1);
    void on_powerOutageCheckBox_stateChanged(int arg1);
    void on_powerOutageSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Simulation* simulation;
    BuildingSetting *buildingSetting;
    std::vector<ElevatorSetting*> elevatorSettings;
    std::vector<PassengerSetting*> passengerSettings;

    int numElevators;
    int numFloors;
    int numPassengers;

    void updateUI();
    void updateElevatorMenus();
    void addElevatorMenu(int);
    void updatePassengerMenus();
    void addPassengerMenu(int);
    void clearLayout(QLayout*);
};
#endif // MAINWINDOW_H
