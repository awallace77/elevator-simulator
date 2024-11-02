#ifndef SIMULATION_COMPONENT_H
#define SIMULATION_COMPONENT_H

#include <QWidget>

class SimulationComponent : public QWidget {
    Q_OBJECT

    public:
        explicit SimulationComponent(QWidget *parent = nullptr) : QWidget(parent) {}
        virtual void updateUI()=0;
        virtual void initUI()=0;

};

#endif
