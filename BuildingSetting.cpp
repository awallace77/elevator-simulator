#include "BuildingSetting.h"
#include <QStringList>

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

void BuildingSetting::setSafeFloors(const QString &sf) {
    safeFloors.clear();
    QStringList items = sf.split(",");
    for(const QString &item : items) safeFloors.push_back(item.toInt() - 1); // -1 for the index of the safe floor
}

// getters
bool BuildingSetting::getFire() const { return fire; }
int BuildingSetting::getFireTime() const { return fireTime; }
bool BuildingSetting::getPowerOutage() const { return powerOutage; }
int BuildingSetting::getPowerOutageTime() const { return powerOutageTime; }
const std::vector<int>& BuildingSetting::getSafeFloors() const { return safeFloors; }

