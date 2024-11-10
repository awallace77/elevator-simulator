/********************************************************************************
** Form generated from reading UI file 'Elevator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEVATOR_H
#define UI_ELEVATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elevator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *elevatorLabel;
    QGridLayout *gridLayout;
    QVBoxLayout *elevator;
    QVBoxLayout *elevatorInfoVLayout;
    QLabel *elevatorFloorLabel;
    QLabel *elevatorStateLabel;
    QLabel *elevatorCapactiyLabel;
    QLabel *elevatorDirectionLabel;
    QLabel *elevatorPassengersLabel;
    QGridLayout *elevatorIndoorLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Elevator)
    {
        if (Elevator->objectName().isEmpty())
            Elevator->setObjectName(QString::fromUtf8("Elevator"));
        Elevator->resize(183, 261);
        Elevator->setStyleSheet(QString::fromUtf8("margin:0px;"));
        verticalLayout = new QVBoxLayout(Elevator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        elevatorLabel = new QLabel(Elevator);
        elevatorLabel->setObjectName(QString::fromUtf8("elevatorLabel"));

        verticalLayout->addWidget(elevatorLabel);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        elevator = new QVBoxLayout();
        elevator->setSpacing(0);
        elevator->setObjectName(QString::fromUtf8("elevator"));

        gridLayout->addLayout(elevator, 0, 0, 1, 1);

        elevatorInfoVLayout = new QVBoxLayout();
        elevatorInfoVLayout->setObjectName(QString::fromUtf8("elevatorInfoVLayout"));
        elevatorFloorLabel = new QLabel(Elevator);
        elevatorFloorLabel->setObjectName(QString::fromUtf8("elevatorFloorLabel"));

        elevatorInfoVLayout->addWidget(elevatorFloorLabel);

        elevatorStateLabel = new QLabel(Elevator);
        elevatorStateLabel->setObjectName(QString::fromUtf8("elevatorStateLabel"));

        elevatorInfoVLayout->addWidget(elevatorStateLabel);

        elevatorCapactiyLabel = new QLabel(Elevator);
        elevatorCapactiyLabel->setObjectName(QString::fromUtf8("elevatorCapactiyLabel"));

        elevatorInfoVLayout->addWidget(elevatorCapactiyLabel);

        elevatorDirectionLabel = new QLabel(Elevator);
        elevatorDirectionLabel->setObjectName(QString::fromUtf8("elevatorDirectionLabel"));

        elevatorInfoVLayout->addWidget(elevatorDirectionLabel);

        elevatorPassengersLabel = new QLabel(Elevator);
        elevatorPassengersLabel->setObjectName(QString::fromUtf8("elevatorPassengersLabel"));

        elevatorInfoVLayout->addWidget(elevatorPassengersLabel);


        gridLayout->addLayout(elevatorInfoVLayout, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        elevatorIndoorLayout = new QGridLayout();
        elevatorIndoorLayout->setObjectName(QString::fromUtf8("elevatorIndoorLayout"));

        verticalLayout->addLayout(elevatorIndoorLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(1, 5);

        retranslateUi(Elevator);

        QMetaObject::connectSlotsByName(Elevator);
    } // setupUi

    void retranslateUi(QWidget *Elevator)
    {
        Elevator->setWindowTitle(QCoreApplication::translate("Elevator", "Form", nullptr));
        elevatorLabel->setText(QCoreApplication::translate("Elevator", "Elevator 1", nullptr));
        elevatorFloorLabel->setText(QCoreApplication::translate("Elevator", "Floor 1", nullptr));
        elevatorStateLabel->setText(QCoreApplication::translate("Elevator", "State", nullptr));
        elevatorCapactiyLabel->setText(QCoreApplication::translate("Elevator", "Capacity", nullptr));
        elevatorDirectionLabel->setText(QCoreApplication::translate("Elevator", "Direction", nullptr));
        elevatorPassengersLabel->setText(QCoreApplication::translate("Elevator", "Passengers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Elevator: public Ui_Elevator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEVATOR_H
