//
// Created by Ales1098 on 28.03.2018.
//

#include "CREATE.h"
//#include "WORD.h"
#include <iostream>

CREATE::CREATE(){
     the_word= new WORD[M];
     //the_word[0]=*(new WORD);
     int Ndef[4]={1,3,4,5};
     WORD* the_word=new WORD("hjfdfjh",3,Ndef);
     the_word[0]=*the_word;

     int Ndef1[]={1,4,6,8};
     the_word=new WORD("abcdfer",5,Ndef1);
     the_word[1]=*the_word;

     int Ndef2[]={2,4,6,7,8};
     the_word=new WORD("fdjhjfd",7,Ndef2);
     the_word[2]=*the_word;
}

CREATE::~CREATE()
{

}