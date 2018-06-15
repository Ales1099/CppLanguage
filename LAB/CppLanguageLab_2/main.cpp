#include <iostream>
#include "Tree.h"
#include "Apple.h"
#include "Pear.h"
#include "Cherry.h"
int main(){
    Apple *apple;
    apple = new Apple("apple",1,"Stiv Gugobs",10,8);
    Pear *pear;
    pear = new Pear("pear",2,"West England",7,3);
    Cherry *cherry;
    cherry = new Cherry("cherry",0,"Bes",20,3);
    Tree* tree[MAX];
    tree[apple->getNumber()]=apple;
    tree[pear->getNumber()]=pear;
    tree[cherry->getNumber()]=cherry;
    for(int i=0; i<3; ++i){
        std::cout<<"---------------------------------------------------------------------------------\n";
        std::cout<<i+1<<" | "<<tree[i]->getNameOfTree()<<" - ";
        if(tree[i]->getResultOfFrustration()) std::cout<<"YES! | ";
        else std::cout<<"NO! | "; std::cout<<"original part - "; tree[i]->getTheOriginalPartClass(); std::cout<<" |"<<std::endl;
        std::cout<<"---------------------------------------------------------------------------------\n";
    }
    system("pause");
    return 0;
}