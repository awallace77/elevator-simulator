/********************************************************************************
** Form generated from reading UI file 'Floor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOOR_H
#define UI_FLOOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Floor
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *buttonLayout;

    void setupUi(QWidget *Floor)
    {
        if (Floor->objectName().isEmpty())
            Floor->setObjectName(QString::fromUtf8("Floor"));
        Floor->resize(251, 143);
        horizontalLayout = new QHBoxLayout(Floor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Floor);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        line = new QFrame(Floor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(7);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(0, 0));
        line->setSizeIncrement(QSize(0, 1));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));

        horizontalLayout->addLayout(buttonLayout);


        retranslateUi(Floor);

        QMetaObject::connectSlotsByName(Floor);
    } // setupUi

    void retranslateUi(QWidget *Floor)
    {
        Floor->setWindowTitle(QCoreApplication::translate("Floor", "Form", nullptr));
        label->setText(QCoreApplication::translate("Floor", "Floor i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Floor: public Ui_Floor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOOR_H
