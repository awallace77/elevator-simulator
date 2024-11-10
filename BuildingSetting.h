#ifndef BUILDINGSETTING_H
#define BUILDINGSETTING_H

#include <QString>
#include <vector>

class BuildingSetting {
public:
    BuildingSetting();

    void setFire(bool);
    void setFireTime(int);
    void setPowerOutage(bool);
    void setPowerOutageTime(int);
    void setSafeFloors(const QString&);
    
    bool getFire() const;
    int getFireTime() const;
    bool getPowerOutage() const;
    int getPowerOutageTime() const;
    const std::vector<int>& getSafeFloors() const;

private:
    bool fire;
    int fireTime;
    bool powerOutage;
    int powerOutageTime;
    std::vector<int> safeFloors;
};

#endif // BUILDINGSETTING_H
