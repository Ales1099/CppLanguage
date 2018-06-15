//
// Created by Ales1098 on 05.04.2018.
//

#ifndef CPPLANGLAB1_WORD_H
#define CPPLANGLAB1_WORD_H

#include <iostream>
#include <string>
#define N 3
using namespace std;
class Word {
private:
    string  the_word;
    int the_page;
    int the_number[10];
public:
    Word();
    Word(string  word, int page, int number[]);
    void setWord(string word, int page, int number[]);
    int getpage();
    void writeWord();
    void write_word();
    void write_number();
    string *the_buffer=&the_word;
};


#endif //CPPLANGLAB1_WORD_H
