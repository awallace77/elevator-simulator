#ifndef BUTTON_H
#define BUTTON_H

#include "SimulationComponent.h"

class Button : public SimulationComponent {
    Q_OBJECT
    
    public:
	explicit Button(QWidget *parent = nullptr) : SimulationComponent(parent) {
	   this->isOn = false; 
	}
	virtual void press()=0;
	virtual void updateUI()=0;
	void on()  { isOn = true;  }
	void off() { isOn = false; }
	QString getState() {
	    return isOn ? "Active" : "Inactive";
	}

    private:
	bool isOn;
	virtual void initUI()=0;
};

#endif
