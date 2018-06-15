//
// Created by Ales1098 on 31.05.2018.
//

#ifndef RGZCPPLANGUAGE_BIGDECIMAL_H
#define RGZCPPLANGUAGE_BIGDECIMAL_H


#include <cstdlib>
#include <iostream>
#include <cstring>

class BigDecimal {
private:

    unsigned char * bigNumber;
    int lengthOfBigNumber;

public:
    BigDecimal(unsigned char * number);
    BigDecimal();
    //функции по умолчанию, помогают в дургих функциях
    void write();//вывод
    int length(unsigned char * number);//длинна числа
    //логические операторы
    operator int();
    operator bool();
    operator unsigned char();
    unsigned char* getNum();
    bool const operator>(const BigDecimal &num);
    bool const operator<(const BigDecimal &num);
    bool const operator==(const BigDecimal &num);
    bool const operator<=(const BigDecimal &num);
    bool const operator>=(const BigDecimal &num);
    bool const operator!=(const BigDecimal &num);
    bool const operator!();
    BigDecimal operator=(BigDecimal  number);
  //  friend BigDecimal & std::ostream(std::ostream os, const BigDecimal & num);
    /*Арифметические операторы*/

    //Сложение
    friend BigDecimal operator+(const BigDecimal &num1, const BigDecimal &num2);
    BigDecimal operator+=(  BigDecimal right);
    BigDecimal operator++();
    BigDecimal operator++(int);
    BigDecimal operator+(unsigned char *number);
    //вычитание
    friend BigDecimal operator-(const BigDecimal &num1, const BigDecimal &num2);
    BigDecimal operator-=(const BigDecimal &num);
    BigDecimal operator--();
    BigDecimal operator--(int);
    BigDecimal operator-(unsigned char * number);
    //умножение
    friend BigDecimal operator*(const BigDecimal &num1, const BigDecimal &num2);
    BigDecimal operator*=(const BigDecimal &num);
    BigDecimal operator*(unsigned char *number);

};



#endif //RGZCPPLANGUAGE_BIGDECIMAL_H
