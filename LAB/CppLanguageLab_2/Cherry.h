//
// Created by Ales1098 on 16.05.2018.
//

#ifndef PROGRAMMINGLANGUAGELAB2_10_CHERRY_H
#define PROGRAMMINGLANGUAGELAB2_10_CHERRY_H

#include "Tree.h"

class Cherry: public virtual Tree{
private:
    int timeOfLive=25;
    int informationAboutFrustration=0;
   // int thePosition=0;
    std::string nameOfTree;
    std::string originalPart="dacha babuchki";
public:
    void getTheOriginalPartClass() const ;
    Cherry(std::string name, int number, std::string originalPart, int time, int information):
            nameOfTree(name),originalPart(originalPart),timeOfLive(time),informationAboutFrustration(information), Tree(number){  };
    ~Cherry(){};
    std::string getNameOfTree() const { return nameOfTree;};
    bool getResultOfFrustration() const {if(timeOfLive>=20 && informationAboutFrustration>=3) return true;
        return false;}
};


#endif //PROGRAMMINGLANGUAGELAB2_10_CHERRY_H
