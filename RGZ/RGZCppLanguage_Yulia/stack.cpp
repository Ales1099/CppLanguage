//
// Created by Ales1098 on 04.06.2018.
//

#include "stack.h"

stack::stack() {
top=nullptr;
}


element *stack::insert(element * head, text *us) {
    element * pointer=new element;
    pointer->str=us;
    if(head== nullptr){
        head=pointer;
        pointer->next= head;
        return head;
    }
    pointer->next=head;
    element * cur;
    for(cur=head; cur->next!=head; cur=cur->next);
    cur->next=pointer;
    head=pointer;
    return head;

}

void stack::add(text * us,int position) {

    top=insert(top,us);
    top->position=position;

}

void stack::printOneElemnent(element * head) {

    if( head == nullptr ) std::cout<<"List is blank!\n";
    else std::cout << head->position << ") "; head->str->getString(); std::cout << std::endl;

}

void stack::print() {

    std::cout<<"Data from list: \n---------------------\n"<<std::endl;

    if(top== nullptr) {std::cout<<"NULL\n";}
    else{
        element * spisok=top;
        do
        {
            printOneElemnent(spisok);
            spisok=spisok->next;
        } while (spisok!=top);
    }
    std::cout<<"\n---------------------\n";

}


bool stack::correct(char *value1, char *value2) {
    int p=0;

    for(int u=0; u<strlen((char*)value1); ++u)
    {
        if(value1[u]-'0'==value2[u]-'0') p=1;
        else p=2;
    }

    return p == 1 ? true: false;
}

element* stack::findOfPosition(int num) {
    if(top== nullptr)
    {
        std::cout<<"list is blank!";
        return nullptr;
    }

    do {
        if(num==top->position) return top;
        top=top->next;
    } while (top!= nullptr);
    return nullptr;
}

element *stack::destroyed() {
    if(top == nullptr) {std::cout<<"List is blank!"<<std::endl;
        return nullptr;}
        element * pointer=top;
    if(pointer->next==top){std::cout<<"List is empty!"<<std::endl; top= nullptr; free(pointer);
        return top;}
    else {
        element *spisok = top->next;
        top->next = top->next->next;
        free(spisok);
        top=destroyed();
        return top;
    }
}


