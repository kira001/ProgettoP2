#include "TroopSpawner.h"

/******************** CONSTRUCTORS/DESTRUCTORS  ********************/
TroopSpawner::TroopSpawner(string n,unsigned int mc,rarity cr, unsigned int cl,string desc,
                           double s,double th,double hxs,double dxs,
                           double sdd,double r,unsigned int c,string td)
                           :Troop(n,mc,cr,cl,desc,s,th,hxs,dxs,sdd,r,c),timeDesc(td){}
TroopSpawner::TroopSpawner(const TroopSpawner& x):Card(x),Troop(x),timeDesc(x.getTimeDesc()){}

/******************** GETTERS/SETTERS ********************/

//GETTERS
   string TroopSpawner::getTimeDesc() const{return timeDesc;}

//SETTERS
   void TroopSpawner::setTimeDesc(string td){timeDesc=td;}

/******************** METHODS ********************/

   void TroopSpawner::lvlUpgrade(){
       Troop::lvlUpgrade();
   }
   void TroopSpawner::lvlDowngrade(){
       Troop::lvlDowngrade();
   }
   QJsonObject TroopSpawner::writeJson() const
   {
       QJsonObject TSjson = Troop::writeJson();
       TSjson["Type"] = QString::fromStdString(getType());
       TSjson["Time and description"] =QString::fromStdString(getTimeDesc());
       return TSjson;
   }
   void TroopSpawner::readJson(const QJsonObject &obj)
   {   Troop::readJson(obj);
       if (obj.contains("Time and Description") && obj["Time and Description"].isString())
           setTimeDesc(obj["Time and Description"].toString().toStdString());

   }
   string TroopSpawner::getType() const{return "Troop Spawner";}

   TroopSpawner* TroopSpawner::clone() const{return new TroopSpawner(*this);}
