/********************************************************************************
** Form generated from reading UI file 'Door.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOOR_H
#define UI_DOOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Door
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *doorGroupBox;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;

    void setupUi(QWidget *Door)
    {
        if (Door->objectName().isEmpty())
            Door->setObjectName(QString::fromUtf8("Door"));
        Door->resize(93, 191);
        verticalLayout = new QVBoxLayout(Door);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doorGroupBox = new QGroupBox(Door);
        doorGroupBox->setObjectName(QString::fromUtf8("doorGroupBox"));
        doorGroupBox->setMinimumSize(QSize(50, 100));
        doorGroupBox->setMaximumSize(QSize(400, 800));
        doorGroupBox->setStyleSheet(QString::fromUtf8("background: #e3e3e3;"));
        verticalLayout_2 = new QVBoxLayout(doorGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        line = new QFrame(doorGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(doorGroupBox);


        retranslateUi(Door);

        QMetaObject::connectSlotsByName(Door);
    } // setupUi

    void retranslateUi(QWidget *Door)
    {
        Door->setWindowTitle(QCoreApplication::translate("Door", "Form", nullptr));
        doorGroupBox->setTitle(QCoreApplication::translate("Door", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Door: public Ui_Door {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOOR_H
