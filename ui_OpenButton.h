/********************************************************************************
** Form generated from reading UI file 'OpenButton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENBUTTON_H
#define UI_OPENBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenButton
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *OpenButton)
    {
        if (OpenButton->objectName().isEmpty())
            OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->resize(177, 138);
        verticalLayout = new QVBoxLayout(OpenButton);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(OpenButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(OpenButton);

        QMetaObject::connectSlotsByName(OpenButton);
    } // setupUi

    void retranslateUi(QWidget *OpenButton)
    {
        OpenButton->setWindowTitle(QCoreApplication::translate("OpenButton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("OpenButton", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenButton: public Ui_OpenButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENBUTTON_H
