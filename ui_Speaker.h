/********************************************************************************
** Form generated from reading UI file 'Speaker.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEAKER_H
#define UI_SPEAKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Speaker
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *Speaker)
    {
        if (Speaker->objectName().isEmpty())
            Speaker->setObjectName(QString::fromUtf8("Speaker"));
        Speaker->resize(171, 62);
        verticalLayout = new QVBoxLayout(Speaker);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Speaker);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(Speaker);

        QMetaObject::connectSlotsByName(Speaker);
    } // setupUi

    void retranslateUi(QWidget *Speaker)
    {
        Speaker->setWindowTitle(QCoreApplication::translate("Speaker", "Form", nullptr));
        label->setText(QCoreApplication::translate("Speaker", "Speaker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Speaker: public Ui_Speaker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEAKER_H
