//
// Created by Ales1098 on 03.06.2018.
//

#include "date.h"

date::date() {

    the_day=23;
    the_month=3;
    the_year=1999;

}

date::date(int its_day, int its_month, int its_year) {
    if(check_correct_for_day(&its_day))  the_day=its_day;
    if(check_correct_for_moth(&its_month))the_month=its_month;
    if(check_correct_for_year(&its_year)) the_year=its_year;

}

bool date::check_correct_for_day(int *user_day) {
    if(1<=*user_day && *user_day<=31) return true;
    return false;
}

bool date::check_correct_for_moth(int *user_month) {
    if(1<=*user_month && *user_month<=12) return true;
    return false;
}

bool date::check_correct_for_year(int *user_year) {
    if(*user_year>0) return true;
    return false;
}

bool const date::operator>(const date &user_date) {
    return (*this).the_day>=user_date.the_day && (*this).the_month>=user_date.the_month && (*this).the_year>=user_date.the_year;
}

bool const date::operator<(const date &user_date) {
    return (*this).the_day<=user_date.the_day && (*this).the_month<=user_date.the_month && (*this).the_year<=user_date.the_year;
}

bool const date::operator==(const date &user_date) {
    return (*this).the_day==user_date.the_day && (*this).the_month==user_date.the_month && (*this).the_year==user_date.the_year;
}

bool const date::operator>=(const date &user_date) {
    return (*this)>user_date || (*this)==user_date;
}

bool const date::operator<=(const date &user_date) {
    return (*this)<user_date || (*this)==user_date;
}

bool const date::operator!=(const date &user_date) {
    return !((*this)==user_date);
}

bool const date::operator!() {
    if((*this)==(*this)) return false;
    return true;
}

const date operator+(const date &user_date, const date &user_date1) {
    date result;
    int for_day;
    int for_month;
    int for_year;

    for_day=user_date.the_day + user_date1.the_day;

    for_month=user_date.the_month + user_date1.the_month;

    for_year=user_date.the_year+user_date1.the_year;

    if(for_day > 31)
    {
        for_day = for_day - 30;
        for_month += 1;
    }

    if(for_month > 12)
    {
        for_month=for_month-12;
        for_year+=1;
    }

    result.the_day=for_day;
    result.the_month=for_month;
    result.the_year=for_year;

    return result;


}

void date::print_date() {

    std::cout<<this->the_day<<"."<<this->the_month<<"."<<this->the_year;

}

const date date::operator+=(const date &user_date) {
    return (*this)=(*this)+user_date;
}

const date date::operator++() {
    date help= date(1);
    return (*this)=(*this)+help;
}

const date date::operator++(int) {
    date help = (*this);
    ++(*this);
    return help;
}

const date date::operator+(int number) {
    date help = date(number);
    (*this)+=help;
    return (*this);
}

const date operator-(const date &user_date, const date &unser_date1) {
    date result;
    int for_day;
    int for_month;
    int for_year;

    for_day=user_date.the_day-unser_date1.the_day;
    for_month=user_date.the_month-unser_date1.the_month;
    for_year=user_date.the_year-unser_date1.the_year;

    if(for_day<0) for_day+=31;
    if(for_month<=0) for_month+=12;
    if(for_year<0) for_year=(-for_year);

    result.the_day=for_day;
    result.the_month=for_month;
    result.the_year=for_year;

    return result;
}

const date date::operator-=(const date &user_date) {
    return (*this)=(*this)-user_date;
}

const date date::operator--() {
    date help = date(1);
    return (*this)=(*this)-help;
}

const date date::operator--(int) {
    date help=(*this);
    --(*this);
    return help;
}

const date date::operator-(int number) {
    date help=date(number);
    return (*this)=(*this)-help;
}

date::date(int its_day) {

    if(check_correct_for_day(&its_day)) the_day=its_day;
    the_month=0;
    the_year=0;

}

date date::operator=(date day) {
    this->the_day=day.the_day; this->the_month=day.the_month; this->the_year=day.the_year;
    return (*this);
}







