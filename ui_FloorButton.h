/********************************************************************************
** Form generated from reading UI file 'FloorButton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOORBUTTON_H
#define UI_FLOORBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FloorButton
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *FloorButton)
    {
        if (FloorButton->objectName().isEmpty())
            FloorButton->setObjectName(QString::fromUtf8("FloorButton"));
        FloorButton->resize(172, 66);
        verticalLayout = new QVBoxLayout(FloorButton);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(FloorButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(FloorButton);

        QMetaObject::connectSlotsByName(FloorButton);
    } // setupUi

    void retranslateUi(QWidget *FloorButton)
    {
        FloorButton->setWindowTitle(QCoreApplication::translate("FloorButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FloorButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FloorButton: public Ui_FloorButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOORBUTTON_H
