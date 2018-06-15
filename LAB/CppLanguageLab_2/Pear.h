//
// Created by Ales1098 on 16.05.2018.
//

#ifndef PROGRAMMINGLANGUAGELAB2_10_PEAR_H
#define PROGRAMMINGLANGUAGELAB2_10_PEAR_H

#include "Tree.h"

class Pear: public virtual Tree{
private:
    int timeOfLive;
    int informationAboutFrustration;
    //int thePosition=2;
    std::string nameOfTree;
    std::string originalPart;
public:
    Pear(std::string name, int number, std::string located, int time, int information):
            nameOfTree(name),originalPart(located),timeOfLive(time),informationAboutFrustration(information),Tree(number){};
    ~Pear(){};
    std::string getNameOfTree() const { return nameOfTree;};
    bool getResultOfFrustration() const {if(timeOfLive>=8 && informationAboutFrustration>=1) return true;
        return false;}
    void getTheOriginalPartClass() const ;
};


#endif //PROGRAMMINGLANGUAGELAB2_10_PEAR_H
