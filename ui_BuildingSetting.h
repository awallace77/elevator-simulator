/********************************************************************************
** Form generated from reading UI file 'BuildingSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDINGSETTING_H
#define UI_BUILDINGSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildingSetting
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QCheckBox *fireCheckBox;
    QSpinBox *fireSpinBox;
    QCheckBox *powerOutageCheckBox;
    QSpinBox *powerOutageSpinBox;

    void setupUi(QWidget *BuildingSetting)
    {
        if (BuildingSetting->objectName().isEmpty())
            BuildingSetting->setObjectName(QString::fromUtf8("BuildingSetting"));
        BuildingSetting->resize(400, 300);
        formLayoutWidget = new QWidget(BuildingSetting);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 60, 174, 83));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        fireCheckBox = new QCheckBox(formLayoutWidget);
        fireCheckBox->setObjectName(QString::fromUtf8("fireCheckBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, fireCheckBox);

        fireSpinBox = new QSpinBox(formLayoutWidget);
        fireSpinBox->setObjectName(QString::fromUtf8("fireSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fireSpinBox);

        powerOutageCheckBox = new QCheckBox(formLayoutWidget);
        powerOutageCheckBox->setObjectName(QString::fromUtf8("powerOutageCheckBox"));

        formLayout->setWidget(2, QFormLayout::LabelRole, powerOutageCheckBox);

        powerOutageSpinBox = new QSpinBox(formLayoutWidget);
        powerOutageSpinBox->setObjectName(QString::fromUtf8("powerOutageSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, powerOutageSpinBox);


        retranslateUi(BuildingSetting);

        QMetaObject::connectSlotsByName(BuildingSetting);
    } // setupUi

    void retranslateUi(QWidget *BuildingSetting)
    {
        BuildingSetting->setWindowTitle(QCoreApplication::translate("BuildingSetting", "Form", nullptr));
        label->setText(QCoreApplication::translate("BuildingSetting", "Building Settings", nullptr));
        fireCheckBox->setText(QCoreApplication::translate("BuildingSetting", "Fire", nullptr));
        powerOutageCheckBox->setText(QCoreApplication::translate("BuildingSetting", "Power Outage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuildingSetting: public Ui_BuildingSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDINGSETTING_H
