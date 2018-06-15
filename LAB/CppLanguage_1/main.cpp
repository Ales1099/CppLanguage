#include <iostream>
#include "Mass.h"

/*Лабораторная работа по языка программирования №1. Вариант 10*/

int main() {
    setlocale(LC_ALL,"RUS");
    Mass* mass=new Mass();
    mass->printMass();
    cout<<"Sort 1"<<endl;
    mass->printsortA();
    cout<<endl;
    cout<<"Sort 2"<<endl;
    mass->printsortB();
    cout<<endl;
    cout<<"Sort 3"<<endl;
    mass->printsortC();
    cout<<endl;
    system("pause");
    return 0;
}