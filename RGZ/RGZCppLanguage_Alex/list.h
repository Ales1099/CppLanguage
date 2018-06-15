//
// Created by Ales1098 on 29.05.2018.
//

#ifndef RGZCPPLANGUAGE_LIST_H
#define RGZCPPLANGUAGE_LIST_H

#include <iostream>
#include <cstring>
#include "BigDecimal.h"

template <typename theType> class list {
private:
    struct bigInt{
        theType number;
        int position=0;
        bigInt * next;

        bigInt(theType data)
        {
            number=data;
            position=0;
            next= nullptr;
        }
    };

    bigInt * top;
public:
    list(){
        top= nullptr;
    }
    list(theType data){
        this->top=new bigInt(data);
        this->top->next=this->top;
    }
    void add( theType data, int positon)
    {
        insert(top,data,positon);
    }
    void print()
    {
        if(top== nullptr)
        {
            std::cout<<"List is blank!\n";
            return;
        }

        bigInt * pointer = top;
        do
        {
            std::cout<<pointer->position<<") ";pointer->number.write(); std::cout<<"\n";
            pointer=pointer->next;
        } while (pointer!=top);

        return;
    }
    void clearn()
    {
        if(top== nullptr) {std::cout<<"NO!"<<std::endl;
            return;
        }
        bigInt * pointer=top;
        if(pointer->next==top){std::cout<<"List is empty!"<<std::endl; top= nullptr; free(pointer);
            return;
        }
        else {
            bigInt *spisok = top->next;
            top->next = top->next->next;
            free(spisok);
            clearn();
        }
    }
    theType find(int position)
    {
        if(top== nullptr)
        {
            std::cout<<"List is blank!\n";
            return nullptr;
        }
        bigInt * poinet = top;
        do{
            if(poinet->position==position) return poinet->number;
            poinet=poinet->next;
        } while (poinet!=top);
        return nullptr;
    }

    void insert(bigInt * head, theType data, int position)
    {
        bigInt * pointer=new bigInt(data);
        pointer->position=position;
        pointer->number=data;
        if(head== nullptr){
            head=pointer;
            pointer->next= pointer;
            return;
        }
        pointer->next=head;
        bigInt * cur;
        for(cur=head; cur->next!=head; cur=cur->next);
        cur->next=pointer;
        head=pointer;
        return;
    }

};


#endif //RGZCPPLANGUAGE_LIST_H
