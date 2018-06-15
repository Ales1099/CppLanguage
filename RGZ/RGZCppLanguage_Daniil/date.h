//
// Created by Ales1098 on 03.06.2018.
//

#ifndef RGZCPPLANGUAGEDANIIL_DATE_H
#define RGZCPPLANGUAGEDANIIL_DATE_H

#include <iostream>

class date {
private:
    int the_day;
    int the_month;
    int the_year;
public:
    date();
    date(int its_day, int its_month, int its_year);
    date(int its_day);
    void print_date();
    bool check_correct_for_day( int *user_day);
    bool check_correct_for_moth( int *user_month);
    bool check_correct_for_year( int *user_year);
    date operator=(date day);

    bool const operator>(const date &user_date);
    bool const operator<(const date &user_date);
    bool const operator==(const date &user_date);
    bool const operator>=(const date &user_date);
    bool const operator<=(const date &user_date);
    bool const operator!=(const date &user_date);
    bool const operator!();

    friend const date operator+(const date &user_date, const date &user_date1);
    const date operator++();
    const date operator++(int);
    const date operator+(int number);
    const date operator+=(const date &user_date);

    friend const date operator-(const date &user_date, const date &unser_date1);
    const date operator--();
    const date operator--(int);
    const date operator-(int number);
    const date operator-=(const date &user_date);
};


#endif //RGZCPPLANGUAGEDANIIL_DATE_H
