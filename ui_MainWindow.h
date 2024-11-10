/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *mainMenuForm;
    QLabel *label;
    QCheckBox *fireCheckBox;
    QSpinBox *fireSpinBox;
    QCheckBox *powerOutageCheckBox;
    QSpinBox *powerOutageSpinBox;
    QFrame *line;
    QLineEdit *safeFloorLineEdit;
    QLabel *safeFloorsLabel;
    QLabel *elevatorLabel;
    QSpinBox *elevatorSpinBox;
    QLabel *passengerLabel;
    QSpinBox *passengerSpinBox;
    QLabel *floorLabel;
    QSpinBox *floorSpinBox;
    QPushButton *updateSimulationButton;
    QPushButton *startSimulationButton;
    QSpacerItem *verticalSpacer;
    QGridLayout *elevatorSettingsLayout;
    QGridLayout *passengerSettingsLayout;
    QMenuBar *menubar;
    QMenu *menuNew_window;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1900, 1016));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mainMenuForm = new QFormLayout();
        mainMenuForm->setObjectName(QString::fromUtf8("mainMenuForm"));
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));

        mainMenuForm->setWidget(0, QFormLayout::SpanningRole, label);

        fireCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        fireCheckBox->setObjectName(QString::fromUtf8("fireCheckBox"));

        mainMenuForm->setWidget(1, QFormLayout::LabelRole, fireCheckBox);

        fireSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        fireSpinBox->setObjectName(QString::fromUtf8("fireSpinBox"));

        mainMenuForm->setWidget(1, QFormLayout::FieldRole, fireSpinBox);

        powerOutageCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        powerOutageCheckBox->setObjectName(QString::fromUtf8("powerOutageCheckBox"));

        mainMenuForm->setWidget(2, QFormLayout::LabelRole, powerOutageCheckBox);

        powerOutageSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        powerOutageSpinBox->setObjectName(QString::fromUtf8("powerOutageSpinBox"));

        mainMenuForm->setWidget(2, QFormLayout::FieldRole, powerOutageSpinBox);

        line = new QFrame(scrollAreaWidgetContents_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(100, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        mainMenuForm->setWidget(5, QFormLayout::SpanningRole, line);

        safeFloorLineEdit = new QLineEdit(scrollAreaWidgetContents_2);
        safeFloorLineEdit->setObjectName(QString::fromUtf8("safeFloorLineEdit"));

        mainMenuForm->setWidget(4, QFormLayout::SpanningRole, safeFloorLineEdit);

        safeFloorsLabel = new QLabel(scrollAreaWidgetContents_2);
        safeFloorsLabel->setObjectName(QString::fromUtf8("safeFloorsLabel"));

        mainMenuForm->setWidget(3, QFormLayout::SpanningRole, safeFloorsLabel);

        elevatorLabel = new QLabel(scrollAreaWidgetContents_2);
        elevatorLabel->setObjectName(QString::fromUtf8("elevatorLabel"));

        mainMenuForm->setWidget(6, QFormLayout::LabelRole, elevatorLabel);

        elevatorSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        elevatorSpinBox->setObjectName(QString::fromUtf8("elevatorSpinBox"));

        mainMenuForm->setWidget(6, QFormLayout::FieldRole, elevatorSpinBox);

        passengerLabel = new QLabel(scrollAreaWidgetContents_2);
        passengerLabel->setObjectName(QString::fromUtf8("passengerLabel"));

        mainMenuForm->setWidget(7, QFormLayout::LabelRole, passengerLabel);

        passengerSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        passengerSpinBox->setObjectName(QString::fromUtf8("passengerSpinBox"));

        mainMenuForm->setWidget(7, QFormLayout::FieldRole, passengerSpinBox);

        floorLabel = new QLabel(scrollAreaWidgetContents_2);
        floorLabel->setObjectName(QString::fromUtf8("floorLabel"));

        mainMenuForm->setWidget(8, QFormLayout::LabelRole, floorLabel);

        floorSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        floorSpinBox->setObjectName(QString::fromUtf8("floorSpinBox"));

        mainMenuForm->setWidget(8, QFormLayout::FieldRole, floorSpinBox);

        updateSimulationButton = new QPushButton(scrollAreaWidgetContents_2);
        updateSimulationButton->setObjectName(QString::fromUtf8("updateSimulationButton"));

        mainMenuForm->setWidget(9, QFormLayout::SpanningRole, updateSimulationButton);

        startSimulationButton = new QPushButton(scrollAreaWidgetContents_2);
        startSimulationButton->setObjectName(QString::fromUtf8("startSimulationButton"));

        mainMenuForm->setWidget(10, QFormLayout::SpanningRole, startSimulationButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainMenuForm->setItem(11, QFormLayout::SpanningRole, verticalSpacer);


        horizontalLayout->addLayout(mainMenuForm);

        elevatorSettingsLayout = new QGridLayout();
        elevatorSettingsLayout->setObjectName(QString::fromUtf8("elevatorSettingsLayout"));

        horizontalLayout->addLayout(elevatorSettingsLayout);

        passengerSettingsLayout = new QGridLayout();
        passengerSettingsLayout->setObjectName(QString::fromUtf8("passengerSettingsLayout"));

        horizontalLayout->addLayout(passengerSettingsLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 5);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        menuNew_window = new QMenu(menubar);
        menuNew_window->setObjectName(QString::fromUtf8("menuNew_window"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNew_window->menuAction());
        menuNew_window->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Elevator Simulator", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Building Settings", nullptr));
        fireCheckBox->setText(QCoreApplication::translate("MainWindow", "Fire", nullptr));
        powerOutageCheckBox->setText(QCoreApplication::translate("MainWindow", "Power Outage", nullptr));
        safeFloorsLabel->setText(QCoreApplication::translate("MainWindow", "Safe Floors (comma seperated)", nullptr));
        elevatorLabel->setText(QCoreApplication::translate("MainWindow", "Elevators", nullptr));
        passengerLabel->setText(QCoreApplication::translate("MainWindow", "Passengers", nullptr));
        floorLabel->setText(QCoreApplication::translate("MainWindow", "Floors", nullptr));
        updateSimulationButton->setText(QCoreApplication::translate("MainWindow", "Update Simulation", nullptr));
        startSimulationButton->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        menuNew_window->setTitle(QCoreApplication::translate("MainWindow", "ElevatorSimulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
