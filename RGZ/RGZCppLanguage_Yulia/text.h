//
// Created by Ales1098 on 02.06.2018.
//

#ifndef RGZCPPLANGUAGEYULIA_TEXT_H
#define RGZCPPLANGUAGEYULIA_TEXT_H

#include <iostream>
#include <cstdlib>

class text {
private:
    char * stringOfText;
    int lengthOfStringText;
public:
    text();
    text(char* stringusers);
    //функция определения длины строки
    int textlen(char * stringUsers);
    //Алгебраичские операторы
    friend text operator+(text &stringOne, text &stringTwo); //конкатенация
    text operator+=(text &stringUser);//увеличениие одной строки на другую
    text operator+(char * usersText);
    //Логические операторы
    bool const operator<(const text &stringOne); //меньше
    bool const operator>(const text &stringOne); //больше
    bool const operator==(const text &stringOne); //равно
    bool const operator>=(const text &stringOne);//больше или равно
    bool const operator<=(const text &stringOne);//меньше или равно
    bool const operator!=(const text &stringOne);//не равно
    //фнукция определяет равенство друх строк
    bool corrected(char * stringOne, char * stringTwo);
    //вывод длинны данной строки
    int getLength();
    //вывод строки
    void getString(){ std::cout<<stringOfText<<"\n";};
    //склеивание строк
    char * strcopipaste(char * one, char * two);
};


#endif //RGZCPPLANGUAGEYULIA_TEXT_H
