/********************************************************************************
** Form generated from reading UI file 'Passenger.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGER_H
#define UI_PASSENGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passenger
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *passengerLabel;
    QLabel *stateLabel;
    QLabel *currentFloorLabel;
    QLabel *currentElevatorLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Passenger)
    {
        if (Passenger->objectName().isEmpty())
            Passenger->setObjectName(QString::fromUtf8("Passenger"));
        Passenger->resize(217, 110);
        Passenger->setStyleSheet(QString::fromUtf8("background-color: 	rgb(193, 225, 193);"));
        verticalLayout = new QVBoxLayout(Passenger);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        passengerLabel = new QLabel(Passenger);
        passengerLabel->setObjectName(QString::fromUtf8("passengerLabel"));
        passengerLabel->setStyleSheet(QString::fromUtf8("font: 75 10pt \"DejaVu Sans\";\n"
""));

        verticalLayout->addWidget(passengerLabel);

        stateLabel = new QLabel(Passenger);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));

        verticalLayout->addWidget(stateLabel);

        currentFloorLabel = new QLabel(Passenger);
        currentFloorLabel->setObjectName(QString::fromUtf8("currentFloorLabel"));

        verticalLayout->addWidget(currentFloorLabel);

        currentElevatorLabel = new QLabel(Passenger);
        currentElevatorLabel->setObjectName(QString::fromUtf8("currentElevatorLabel"));

        verticalLayout->addWidget(currentElevatorLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Passenger);

        QMetaObject::connectSlotsByName(Passenger);
    } // setupUi

    void retranslateUi(QWidget *Passenger)
    {
        Passenger->setWindowTitle(QCoreApplication::translate("Passenger", "Form", nullptr));
        passengerLabel->setText(QCoreApplication::translate("Passenger", "Passenger i", nullptr));
        stateLabel->setText(QCoreApplication::translate("Passenger", "State", nullptr));
        currentFloorLabel->setText(QCoreApplication::translate("Passenger", "Current Floor", nullptr));
        currentElevatorLabel->setText(QCoreApplication::translate("Passenger", "Current Elevator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passenger: public Ui_Passenger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGER_H
