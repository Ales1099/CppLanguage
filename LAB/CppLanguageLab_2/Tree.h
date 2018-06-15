//
// Created by Ales1098 on 16.05.2018.
//

#ifndef PROGRAMMINGLANGUAGELAB2_10_TREE_H
#define PROGRAMMINGLANGUAGELAB2_10_TREE_H
#define MAX 3
#include <iostream>

virtual class Tree {
protected:
    int number;
public:
    Tree();
    Tree(int data): number(data){};
    virtual bool getResultOfFrustration() const = 0;
    virtual std::string getNameOfTree() const = 0;
    virtual void getTheOriginalPartClass() const = 0;
    int getNumber() const ;
    ~Tree(){};
};


#endif //PROGRAMMINGLANGUAGELAB2_10_TREE_H
