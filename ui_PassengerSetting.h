/********************************************************************************
** Form generated from reading UI file 'PassengerSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERSETTING_H
#define UI_PASSENGERSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassengerSetting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *passengerSettingsLabel;
    QFormLayout *formLayout;
    QLabel *timeFloorButtonPressedLabel;
    QSpinBox *timeFloorButtonPressedSpinBox;
    QLabel *startFloorLabel;
    QSpinBox *startFloorSpinBox;
    QLabel *directionLabel;
    QComboBox *directionComboBox;
    QLabel *destinationFloorLabel;
    QSpinBox *destinationFloorSpinBox;
    QCheckBox *helpCheckBox;
    QSpinBox *helpSpinBox;
    QCheckBox *openDoorCheckBox;
    QSpinBox *openDoorSpinBox;
    QCheckBox *closeDoorCheckBox;
    QSpinBox *closeDoorSpinBox;

    void setupUi(QWidget *PassengerSetting)
    {
        if (PassengerSetting->objectName().isEmpty())
            PassengerSetting->setObjectName(QString::fromUtf8("PassengerSetting"));
        PassengerSetting->resize(309, 260);
        verticalLayout = new QVBoxLayout(PassengerSetting);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        passengerSettingsLabel = new QLabel(PassengerSetting);
        passengerSettingsLabel->setObjectName(QString::fromUtf8("passengerSettingsLabel"));

        verticalLayout->addWidget(passengerSettingsLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        timeFloorButtonPressedLabel = new QLabel(PassengerSetting);
        timeFloorButtonPressedLabel->setObjectName(QString::fromUtf8("timeFloorButtonPressedLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, timeFloorButtonPressedLabel);

        timeFloorButtonPressedSpinBox = new QSpinBox(PassengerSetting);
        timeFloorButtonPressedSpinBox->setObjectName(QString::fromUtf8("timeFloorButtonPressedSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, timeFloorButtonPressedSpinBox);

        startFloorLabel = new QLabel(PassengerSetting);
        startFloorLabel->setObjectName(QString::fromUtf8("startFloorLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, startFloorLabel);

        startFloorSpinBox = new QSpinBox(PassengerSetting);
        startFloorSpinBox->setObjectName(QString::fromUtf8("startFloorSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, startFloorSpinBox);

        directionLabel = new QLabel(PassengerSetting);
        directionLabel->setObjectName(QString::fromUtf8("directionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, directionLabel);

        directionComboBox = new QComboBox(PassengerSetting);
        directionComboBox->setObjectName(QString::fromUtf8("directionComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, directionComboBox);

        destinationFloorLabel = new QLabel(PassengerSetting);
        destinationFloorLabel->setObjectName(QString::fromUtf8("destinationFloorLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, destinationFloorLabel);

        destinationFloorSpinBox = new QSpinBox(PassengerSetting);
        destinationFloorSpinBox->setObjectName(QString::fromUtf8("destinationFloorSpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, destinationFloorSpinBox);

        helpCheckBox = new QCheckBox(PassengerSetting);
        helpCheckBox->setObjectName(QString::fromUtf8("helpCheckBox"));

        formLayout->setWidget(4, QFormLayout::LabelRole, helpCheckBox);

        helpSpinBox = new QSpinBox(PassengerSetting);
        helpSpinBox->setObjectName(QString::fromUtf8("helpSpinBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, helpSpinBox);

        openDoorCheckBox = new QCheckBox(PassengerSetting);
        openDoorCheckBox->setObjectName(QString::fromUtf8("openDoorCheckBox"));

        formLayout->setWidget(5, QFormLayout::LabelRole, openDoorCheckBox);

        openDoorSpinBox = new QSpinBox(PassengerSetting);
        openDoorSpinBox->setObjectName(QString::fromUtf8("openDoorSpinBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, openDoorSpinBox);

        closeDoorCheckBox = new QCheckBox(PassengerSetting);
        closeDoorCheckBox->setObjectName(QString::fromUtf8("closeDoorCheckBox"));

        formLayout->setWidget(6, QFormLayout::LabelRole, closeDoorCheckBox);

        closeDoorSpinBox = new QSpinBox(PassengerSetting);
        closeDoorSpinBox->setObjectName(QString::fromUtf8("closeDoorSpinBox"));

        formLayout->setWidget(6, QFormLayout::FieldRole, closeDoorSpinBox);


        verticalLayout->addLayout(formLayout);


        retranslateUi(PassengerSetting);

        QMetaObject::connectSlotsByName(PassengerSetting);
    } // setupUi

    void retranslateUi(QWidget *PassengerSetting)
    {
        PassengerSetting->setWindowTitle(QCoreApplication::translate("PassengerSetting", "Form", nullptr));
        passengerSettingsLabel->setText(QCoreApplication::translate("PassengerSetting", "Passenger 1 Settings", nullptr));
        timeFloorButtonPressedLabel->setText(QCoreApplication::translate("PassengerSetting", "Time floor button pressed", nullptr));
        startFloorLabel->setText(QCoreApplication::translate("PassengerSetting", "Start floor", nullptr));
        directionLabel->setText(QCoreApplication::translate("PassengerSetting", "Direction", nullptr));
        destinationFloorLabel->setText(QCoreApplication::translate("PassengerSetting", "Destination floor ", nullptr));
        helpCheckBox->setText(QCoreApplication::translate("PassengerSetting", "Help button pressed", nullptr));
        openDoorCheckBox->setText(QCoreApplication::translate("PassengerSetting", "Open door button pressed", nullptr));
        closeDoorCheckBox->setText(QCoreApplication::translate("PassengerSetting", "Close door button pressed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerSetting: public Ui_PassengerSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERSETTING_H
