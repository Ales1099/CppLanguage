//
// Created by Ales1098 on 05.04.2018.
//

#include "Word.h"
#include <iostream>
#include <string>

using namespace std;

void Word::setWord(string word,int page,int number[]) {
    the_word=word;
    the_page=page;
    for(int i=0; i<10; i++) the_number[i]=number[i];
}

Word::Word(string word, int page,int number[]){
    setWord(word,page,number);
}

int Word::getpage() {
    return the_page;
}

void Word::writeWord() {
    cout<<"word - "<<the_word.c_str()<<"   "<<"page: "<<the_page<<"   "<<"number: ";
    for(int i=0; i<the_page; i++) cout<<the_number[i]<<" ";
}

Word::Word(){
    the_word="pofig";
    the_page=3;
    for(int i=0; i<10; i++) the_number[i]=i;
}

void Word::write_word() {
    cout<<the_word;
}

void Word::write_number() {
    cout<<"number: "; for(int i=0; i<the_page; i++) cout<<*(the_number+i)<<" ";
}

