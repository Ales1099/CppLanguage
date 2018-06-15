//
// Created by Ales1098 on 16.05.2018.
//

#ifndef PROGRAMMINGLANGUAGELAB2_10_APPLE_H
#define PROGRAMMINGLANGUAGELAB2_10_APPLE_H

#include "Tree.h"

class Apple: public virtual Tree{
private:
    int timeOfLive;
    int informationAboutFrustration;
    std::string nameOfTree;
    std::string originalPart;
public:
    Apple(std::string name, int number, std::string nameVid, int time, int information):
            nameOfTree(name),originalPart(nameVid),timeOfLive(time), informationAboutFrustration(information),Tree(number){};
    ~Apple(){};
    std::string getNameOfTree() const { return nameOfTree;};
    bool getResultOfFrustration() const {if(timeOfLive>=10 && informationAboutFrustration>=5) return true;
        return false;}
    void getTheOriginalPartClass() const;
};


#endif //PROGRAMMINGLANGUAGELAB2_10_APPLE_H
