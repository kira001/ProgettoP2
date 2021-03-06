#ifndef SPELLTROOPSPAWNER_H
#define SPELLTROOPSPAWNER_H

#include "Spell.h"
#include "Troop.h"

class SpellTroopSpawner:public Spell, public Troop{
private:
   string timeSpawn;

public:
    // CONSTRUCTORS/DESTRUCTORS
    SpellTroopSpawner()=default;
    SpellTroopSpawner(string, string, unsigned int, rarity, unsigned int,string,double,double,double
                      , double, double, double, double, double, double, unsigned int,string);
    SpellTroopSpawner(const SpellTroopSpawner&);
    // GETTERS
    string getTimeSpawn() const;
    // SETTERS
    void setTimeSpawn(string);
    //OVERLOADING
    virtual bool  operator==(const SpellTroopSpawner&) const;
    virtual bool  operator!=(const SpellTroopSpawner&) const;
    // METHODS
    virtual string getType() const;
    virtual void lvlUpgrade();
    virtual void lvlDowngrade();
    virtual SpellTroopSpawner* clone() const;


};

#endif // SPELLTROOPSPAWNER_H
