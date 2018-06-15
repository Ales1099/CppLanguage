//
// Created by Ales1098 on 28.03.2018.
//

#ifndef CPPLANG_CREATE_H
#define CPPLANG_CREATE_H
#define M 3
#include "WORD.h"
//const int q=3;
class CREATE {
private:
    WORD* the_word= new WORD[M];
public:
    CREATE();
    ~CREATE();
    void write_sortA(){
        int u;
        std::cout<<"Enter the sum page: "; std::cin>>u;
        for(int i=0; i<M; i++){
            if(u==the_word[i].get_the_sum_page()) the_word[i].wriet_class_word();
        }
    }
};


#endif //CPPLANG_CREATE_H
