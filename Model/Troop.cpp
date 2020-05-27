#include "Troop.h"

/******************** CONSTRUCTORS/DESTRUCTORS  ********************/
Troop::Troop(string n, unsigned int mana, rarity rar, unsigned int cLevel,string desc, double s,
             double th, double hxs, double dxs, double sdd, double r, unsigned int c):
Card(n,mana,rar,cLevel,desc), shield(s), troopHealth(th), hitxSec(hxs), damagexSec(dxs), spawnDD(sdd),
  range(r),count(c){}
Troop::Troop(const Troop& x):Card(x),shield(x.getShield()),troopHealth(x.getTroopHealth()),hitxSec(x.getHitxSec()),
damagexSec(x.getDamagexSec()),spawnDD(x.getSpawnDD()),range(x.getRange()),count(x.getCount())
{}

/******************** GETTERS/SETTERS ********************/

//GETTERS
   double Troop::getShield() const{return shield;}
   double Troop::getTroopHealth() const{return troopHealth;}
   double Troop::getHitxSec()const{return hitxSec;}
   double Troop::getDamagexSec()const{return damagexSec;}
   double Troop::getSpawnDD()const{return spawnDD;}
   double Troop::getRange()const{return range;}
   unsigned int Troop::getCount()const{return count;}

//SETTERS
   void Troop::setShield(double s){shield=s;}
   void Troop::setTroopHealth(double th){troopHealth=th;}
   void Troop::setHitxSec(double hxs){hitxSec=hxs;}
   void Troop::setDamagexSec(double dxs){damagexSec=dxs;}
   void Troop::setSpawnDD(double sdd){spawnDD=sdd;}
   void Troop::setRange(double r){range=r;}
   void Troop::setCount(unsigned int c){count=c;}


/******************** METHODS ********************/

   double Troop::damage() const{return hitxSec*damagexSec;}

   string Troop::DimRange() const
   {
       if(range>1) return "Medium Range";
       if(range>2) return "Large Range";
           return "Short Range";
   }

   void Troop::upgradeStats(){
       shield= (shield*(100+4*Card::getCardLevel()))/100;
       troopHealth=(troopHealth*(100+8*Card::getCardLevel()))/100;
       hitxSec= (hitxSec*(100+5*Card::getCardLevel()))/100;
       damagexSec=(damagexSec*(100+5*Card::getCardLevel()))/100;
       spawnDD= (spawnDD*(100+6*Card::getCardLevel()))/100;
   }
   void Troop::downgradeStats(){
       shield= (shield*100/(100+4*Card::getCardLevel()));
       troopHealth=(troopHealth*100/(100+8*Card::getCardLevel()));
       hitxSec=(hitxSec*100/(100+5*Card::getCardLevel()));
       damagexSec=(damagexSec*100/(100+5*Card::getCardLevel()));
       spawnDD=(spawnDD*100/(100+6*Card::getCardLevel()));
   }


   void Troop::lvlUpgrade(){

      if(Card::getCardLevel()<Card::getMaxLevel()){
            Card::lvlUpgrade();
            upgradeStats();
      }
   }

   void Troop::lvlDowngrade(){
       if(Card::getCardLevel()>1){
            downgradeStats();
            Card::lvlDowngrade();
       }
   }
   QJsonObject Troop::writeJson() const
   {}
   void Troop::readJson(const QJsonObject &obj)
   {}
   string Troop::getType() const{return "Troop";}
   Troop* Troop::clone() const{return new Troop(*this);}
