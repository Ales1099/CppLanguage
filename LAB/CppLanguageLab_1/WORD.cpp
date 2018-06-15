//
// Created by Ales1098 on 28.03.2018.
//
#include <iostream>
#include <string>
#include "WORD.h"
#define N 20
#define A 10
// : the_word(word), the_sum_page(sum_page), the_number_page(number_page)
WORD::WORD()
{
    the_word = "qwe";
    the_sum_page = 1;
    for(int i = 0; i<A; i++) {
        the_number_page[i] = 1;
    }
}

WORD::WORD(std::string word, int sum_page, int number_page[])
{
    //оставляем пустым
    the_word = word;
    the_sum_page = sum_page;
    for(int i = 0; i<A; i++) {
        the_number_page[i] = number_page[i];
    }
}

void WORD::wriet_class_word() {
    std::cout<<"word: "<<the_word<<"   "<<"sum page: "<<the_sum_page<<"   "<<"number page: "<<*the_number_page<<std::endl;
}

int WORD::get_the_sum_page(){
    return the_sum_page;
}