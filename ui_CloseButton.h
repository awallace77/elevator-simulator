/********************************************************************************
** Form generated from reading UI file 'CloseButton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSEBUTTON_H
#define UI_CLOSEBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloseButton
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *CloseButton)
    {
        if (CloseButton->objectName().isEmpty())
            CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->resize(162, 121);
        verticalLayout = new QVBoxLayout(CloseButton);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(CloseButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(CloseButton);

        QMetaObject::connectSlotsByName(CloseButton);
    } // setupUi

    void retranslateUi(QWidget *CloseButton)
    {
        CloseButton->setWindowTitle(QCoreApplication::translate("CloseButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CloseButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CloseButton: public Ui_CloseButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSEBUTTON_H
