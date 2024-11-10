QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BuildingSetting.cpp \
    CloseButton.cpp \
    DestinationButton.cpp \
    Display.cpp \
    Door.cpp \
    Elevator.cpp \
    ElevatorSetting.cpp \
    Floor.cpp \
    FloorButton.cpp \
    HelpButton.cpp \
    MainWindow.cpp \
    OpenButton.cpp \
    Passenger.cpp \
    PassengerSetting.cpp \
    Simulation.cpp \
    Speaker.cpp \
    main.cpp \
    ElevatorControl.cpp \
    NCStrategy.cpp \
    FloorRequest.cpp \
    SimulationManager.cpp \
    SimulationUpdater.cpp \
    Sensor.cpp

HEADERS += \
    BuildingSetting.h \
    CloseButton.h \
    DestinationButton.h \
    Display.h \
    Door.h \
    Elevator.h \
    ElevatorSetting.h \
    Floor.h \
    FloorButton.h \
    HelpButton.h \
    MainWindow.h \
    ElevatorState.h \
    Direction.h \
    DoorState.h \
    OpenButton.h \
    Passenger.h \
    PassengerState.h \
    PassengerSetting.h \
    Simulation.h \
    SimulationComponent.h \
    Button.h \
    Speaker.h \
    ElevatorControl.h \
    AllocationStrategy.h \
    NCStrategy.h \
    FloorRequest.h \
    SimulationManager.h \
    Random.h \
    SimulationUpdater.h \ 
    Sensor.h

FORMS += \
    CloseButton.ui \
    DestinationButton.ui \
    Display.ui \
    Door.ui \
    Elevator.ui \
    ElevatorSetting.ui \
    Floor.ui \
    FloorButton.ui \
    HelpButton.ui \
    MainWindow.ui \
    OpenButton.ui \
    Passenger.ui \
    PassengerSetting.ui \
    Simulation.ui \
    Speaker.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
