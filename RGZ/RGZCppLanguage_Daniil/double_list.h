//
// Created by Ales1098 on 04.06.2018.
//

#ifndef RGZCPPLANGUAGEDANIIL_DOUBLE_LIST_H
#define RGZCPPLANGUAGEDANIIL_DOUBLE_LIST_H

#include <iostream>
#include "date.h"

template <typename theType> class double_list {
private:
    struct element{
        theType date_in_the_element;
        int position_the_element;
        element * next;
        element * prev;

        element(theType val, int position){
            date_in_the_element=val;
            position_the_element=position;
            next= nullptr;
            prev= nullptr;
        }
    };

    element * top;
public:
    double_list()
    {
        top= nullptr;
    }

    double_list(theType date_user, int position)
    {
        this->top=new element(date_user,position);
        this->top->next=this->top;
        this->top->prev=this->top;
    }

    void print()
    {
        std::cout<<this->top->date_in_the_element<<"\n";
    }

    void add_new_element(theType date_user, int position)
    {
        element * help=this->top->next;
        this->top->next=new element(date_user,position);
        this->top->next->prev=this->top;
        this->top->next->next=help;
    }

    theType find_position(int position)
    {
        if(top== nullptr)
        {
            std::cout<<"NO!\n";
            return 0;
        }

        element * pointer = this->top;
        do
        {
            if(pointer->position_the_element==position) return pointer->date_in_the_element;
            pointer=pointer->next;
        } while(pointer!=top);
    }

    void clearn()
    {
        element* el = this->top->next;
        element *next, *prev;
        prev = el->prev;
        next = el->next;
        prev->next = el->next;
        next->prev = el->prev;
        free(el);
    }

    void display()
    {
        if(top== nullptr)
        {
            std::cout<<"NO!\n";
            return;
        }
        element * pointer = top;
        do{
            std::cout<< pointer->position_the_element<<") "; pointer->date_in_the_element.print_date(); std::cout<<"\n";
            pointer=pointer->next;
        } while(pointer!=top);
    }


};


#endif //RGZCPPLANGUAGEDANIIL_DOUBLE_LIST_H
