/********************************************************************************
** Form generated from reading UI file 'ElevatorSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEVATORSETTING_H
#define UI_ELEVATORSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElevatorSetting
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *elevatorLabel;
    QCheckBox *overloadedCheckBox;
    QSpinBox *overloadedSpinBox;
    QCheckBox *obstacleCheckBox;
    QSpinBox *obstacleSpinBox;
    QLabel *label;
    QSpinBox *capacitySpinBox;

    void setupUi(QWidget *ElevatorSetting)
    {
        if (ElevatorSetting->objectName().isEmpty())
            ElevatorSetting->setObjectName(QString::fromUtf8("ElevatorSetting"));
        ElevatorSetting->resize(172, 133);
        verticalLayout = new QVBoxLayout(ElevatorSetting);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        elevatorLabel = new QLabel(ElevatorSetting);
        elevatorLabel->setObjectName(QString::fromUtf8("elevatorLabel"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, elevatorLabel);

        overloadedCheckBox = new QCheckBox(ElevatorSetting);
        overloadedCheckBox->setObjectName(QString::fromUtf8("overloadedCheckBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, overloadedCheckBox);

        overloadedSpinBox = new QSpinBox(ElevatorSetting);
        overloadedSpinBox->setObjectName(QString::fromUtf8("overloadedSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, overloadedSpinBox);

        obstacleCheckBox = new QCheckBox(ElevatorSetting);
        obstacleCheckBox->setObjectName(QString::fromUtf8("obstacleCheckBox"));

        formLayout->setWidget(2, QFormLayout::LabelRole, obstacleCheckBox);

        obstacleSpinBox = new QSpinBox(ElevatorSetting);
        obstacleSpinBox->setObjectName(QString::fromUtf8("obstacleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, obstacleSpinBox);

        label = new QLabel(ElevatorSetting);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        capacitySpinBox = new QSpinBox(ElevatorSetting);
        capacitySpinBox->setObjectName(QString::fromUtf8("capacitySpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, capacitySpinBox);


        verticalLayout->addLayout(formLayout);


        retranslateUi(ElevatorSetting);

        QMetaObject::connectSlotsByName(ElevatorSetting);
    } // setupUi

    void retranslateUi(QWidget *ElevatorSetting)
    {
        ElevatorSetting->setWindowTitle(QCoreApplication::translate("ElevatorSetting", "Form", nullptr));
        elevatorLabel->setText(QCoreApplication::translate("ElevatorSetting", "Elevator i", nullptr));
        overloadedCheckBox->setText(QCoreApplication::translate("ElevatorSetting", "Overloaded", nullptr));
        obstacleCheckBox->setText(QCoreApplication::translate("ElevatorSetting", "Obstacle", nullptr));
        label->setText(QCoreApplication::translate("ElevatorSetting", "Capacity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ElevatorSetting: public Ui_ElevatorSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEVATORSETTING_H
