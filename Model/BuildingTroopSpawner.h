#ifndef BUILDINGTROOPSPAWNER_H
#define BUILDINGTROOPSPAWNER_H
#include "Building.h"
#include "Troop.h"

class BuildingTroopSpawner: public Building, public Troop{
private:
    double spawnSpeed;
public:
    BuildingTroopSpawner()=default;
    BuildingTroopSpawner(string n, unsigned int mana, rarity rar, unsigned int cLevel,string desc, double bHealth, double lTime,
    double shld,
    double tHealth,
    double hxSec,
    double dxSec,
    double sDD,
    double rng,
    unsigned int cnt,
    double sSpeed);
    BuildingTroopSpawner(const BuildingTroopSpawner& bts);

    double getSpawnSpeed() const;
    void setSpawnSpeed(double sSpeed);
    virtual QJsonObject serializeJson() const;
    virtual void deserializeJson(const QJsonObject& obj);
    virtual void lvlUpgrade();
    virtual void lvlDowngrade();
    virtual string getType() const;
    virtual BuildingTroopSpawner* clone() const;
};
#endif // BUILDINGTROOPSPAWNER_H
