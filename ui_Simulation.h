/********************************************************************************
** Form generated from reading UI file 'Simulation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_H
#define UI_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Simulation
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *elevatorLayout;
    QGridLayout *passengerLayout;
    QGridLayout *floorLayout;
    QHBoxLayout *simulationInfoLayout;
    QLabel *statusLabel;
    QLCDNumber *timeLcdNumber;

    void setupUi(QDialog *Simulation)
    {
        if (Simulation->objectName().isEmpty())
            Simulation->setObjectName(QString::fromUtf8("Simulation"));
        Simulation->resize(1064, 535);
        verticalLayout = new QVBoxLayout(Simulation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        elevatorLayout = new QGridLayout();
        elevatorLayout->setObjectName(QString::fromUtf8("elevatorLayout"));

        horizontalLayout->addLayout(elevatorLayout);

        passengerLayout = new QGridLayout();
        passengerLayout->setObjectName(QString::fromUtf8("passengerLayout"));

        horizontalLayout->addLayout(passengerLayout);

        floorLayout = new QGridLayout();
        floorLayout->setObjectName(QString::fromUtf8("floorLayout"));

        horizontalLayout->addLayout(floorLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        simulationInfoLayout = new QHBoxLayout();
        simulationInfoLayout->setObjectName(QString::fromUtf8("simulationInfoLayout"));
        statusLabel = new QLabel(Simulation);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        simulationInfoLayout->addWidget(statusLabel);

        timeLcdNumber = new QLCDNumber(Simulation);
        timeLcdNumber->setObjectName(QString::fromUtf8("timeLcdNumber"));

        simulationInfoLayout->addWidget(timeLcdNumber);


        verticalLayout->addLayout(simulationInfoLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(Simulation);

        QMetaObject::connectSlotsByName(Simulation);
    } // setupUi

    void retranslateUi(QDialog *Simulation)
    {
        Simulation->setWindowTitle(QCoreApplication::translate("Simulation", "Dialog", nullptr));
        statusLabel->setText(QCoreApplication::translate("Simulation", "Status Label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulation: public Ui_Simulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_H
