#include "BuildingSetting.h"

BuildingSetting::BuildingSetting() {
    this->fire = false;
    this->fireTime = 0;
    this->powerOutage = false;
    this->powerOutageTime = 0;
}

// setters
void BuildingSetting::setFire(bool fire) { this->fire = fire; }
void BuildingSetting::setFireTime(int time) { fireTime = time; }
void BuildingSetting::setPowerOutage(bool outage) { powerOutage = outage; }
void BuildingSetting::setPowerOutageTime(int time) { this->powerOutageTime = time; }

// getters
bool BuildingSetting::getFire() const { return fire; }
int BuildingSetting::getFireTime() const { return fireTime; }
bool BuildingSetting::getPowerOutage() const { return powerOutage; }
int BuildingSetting::getPowerOutageTime() const { return powerOutageTime; }

