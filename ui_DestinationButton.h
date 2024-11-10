/********************************************************************************
** Form generated from reading UI file 'DestinationButton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESTINATIONBUTTON_H
#define UI_DESTINATIONBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DestinationButton
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *DestinationButton)
    {
        if (DestinationButton->objectName().isEmpty())
            DestinationButton->setObjectName(QString::fromUtf8("DestinationButton"));
        DestinationButton->resize(158, 84);
        verticalLayout = new QVBoxLayout(DestinationButton);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(DestinationButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DestinationButton);

        QMetaObject::connectSlotsByName(DestinationButton);
    } // setupUi

    void retranslateUi(QWidget *DestinationButton)
    {
        DestinationButton->setWindowTitle(QCoreApplication::translate("DestinationButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("DestinationButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DestinationButton: public Ui_DestinationButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESTINATIONBUTTON_H
