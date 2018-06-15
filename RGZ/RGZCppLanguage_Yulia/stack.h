//
// Created by Ales1098 on 04.06.2018.
//

#ifndef RGZCPPLANGUAGEYULIA_STACK_H
#define RGZCPPLANGUAGEYULIA_STACK_H

#include <iostream>
#include <cstring>
#include "text.h"

struct element{
    text *str;
    int position;
    element * next;
};
class stack {
private:
   element * top;
public:
    stack();
    void add(text *us, int position);
    void printOneElemnent(element * head);
    void print();
    element * insert(element * head, text *us);
    bool correct(char * value1, char * value2);
    element* findOfPosition(int num);
    element* destroyed();
};


#endif //RGZCPPLANGUAGEYULIA_STACK_H
