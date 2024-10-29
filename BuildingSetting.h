#ifndef BUILDINGSETTING_H
#define BUILDINGSETTING_H


class BuildingSetting {
public:
    BuildingSetting();

    void setFire(bool);
    void setFireTime(int);
    void setPowerOutage(bool);
    void setPowerOutageTime(int);
    
    bool getFire() const;
    int getFireTime() const;
    bool getPowerOutage() const;
    int getPowerOutageTime() const;

private:
    bool fire;
    int fireTime;
    bool powerOutage;
    int powerOutageTime;
};

#endif // BUILDINGSETTING_H
