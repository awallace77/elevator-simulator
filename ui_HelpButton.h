/********************************************************************************
** Form generated from reading UI file 'HelpButton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPBUTTON_H
#define UI_HELPBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpButton
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *HelpButton)
    {
        if (HelpButton->objectName().isEmpty())
            HelpButton->setObjectName(QString::fromUtf8("HelpButton"));
        HelpButton->resize(180, 124);
        verticalLayout = new QVBoxLayout(HelpButton);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(HelpButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(HelpButton);

        QMetaObject::connectSlotsByName(HelpButton);
    } // setupUi

    void retranslateUi(QWidget *HelpButton)
    {
        HelpButton->setWindowTitle(QCoreApplication::translate("HelpButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("HelpButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpButton: public Ui_HelpButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPBUTTON_H
