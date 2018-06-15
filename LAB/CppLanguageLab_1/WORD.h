//
// Created by Ales1098 on 28.03.2018.
//

#ifndef CPPLANG_WORD_H
#define CPPLANG_WORD_H
#include <iostream>
#define N 20
#define A 10
class WORD {
private:
    std::string the_word;
    int the_sum_page;
    int the_number_page[10];
public:
    WORD();
    WORD(std::string word, int sum_page, int number_page[]);
    int get_the_sum_page();

    void wriet_class_word();
};


#endif //CPPLANG_WORD_H
