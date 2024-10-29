#ifndef ELEVATORWINDOW_H
#define ELEVATORWINDOW_H

#include <QMdiSubWindow>
#include <QtGui>
#include <QWidget>

#include "Elevator.h"

namespace Ui {
    class ElevatorWindow;
}

class ElevatorWindow : public QMdiSubWindow {
    Q_OBJECT
public:
    explicit ElevatorWindow(QWidget *parent=nullptr);
    ~ElevatorWindow();
private: 
    Elevator *elevator;
};

#endif // ELEVATORWINDOW_H
