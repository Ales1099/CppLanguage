//
// Created by Ales1098 on 05.04.2018.
//

#ifndef CPPLANGLAB1_MASS_H
#define CPPLANGLAB1_MASS_H

#include "Word.h"
#define N 3
class Mass {
private:
    Word* its_word= new Word[N];
public:
    Mass();
    ~Mass();
    void printMass(){
        for(int i=0; i<N; i++) {its_word[i].writeWord(); cout<<endl;};
    }
    void printsortA();
    void printsortB();
    void printsortC();
};


#endif //CPPLANGLAB1_MASS_H
