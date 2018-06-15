//
// Created by Ales1098 on 05.04.2018.
//

#include "Mass.h"
#include <string>
Mass::Mass() {
    //its_word[0]=*(new Word());

    int A[10]={3,4};
    Word* word=new Word("zxy",2,A);
    its_word[0]=*word;

    int B[10]={1,2,4,5};
    word=new Word("abc",4,B);
    its_word[1]=*word;

    int C[10]={5,6,7,8,9};
    word=new Word("def",5,C);
    its_word[2]=*word;
}

Mass::~Mass() {
    delete its_word;
}

void Mass::printsortA() {
    int u_page;
    int K=0;
    while(1) {
        cout << "Enter a page: ";
        cin >> u_page;
        cout << endl;
        for (int i = 0; i < N; i++)
            if (its_word[i].getpage() > u_page) {
                its_word[i].write_word();
                cout << endl;
                K++;
            }
        if (!(K == 0)) break; else cout << "No!";
    }
    cout<<endl;
}

void Mass::printsortB() {
    for(int i=0; i<N-1; i++)
        for(int j=i+1; j<N; j++)
            if(*its_word[i].the_buffer>*its_word[j].the_buffer){
                Word buffer=its_word[i];
                its_word[i]=its_word[j];
                its_word[j]=buffer;
            }
    for(int i=0; i<N; i++) {
        its_word[i].write_word();
        cout<<endl;
    }
}

void Mass::printsortC() {
    string  u_word;
    int K=0;
    while(1) {
        cout << "Enter a word: ";
        cin >> u_word;
        for (int i = 0; i < N; i++)
            if (u_word == *its_word[i].the_buffer) {
                its_word[i].write_number();
                cout<<endl;
                K++;
            }
        if (!(K == 0)) break; else  cout << "Incorrectly!!!";
    }
}