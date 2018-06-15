#include <iostream>
#include "text.h"
#include "stack.h"
#include <string>
#include <cstring>
int main() {
    stack * a = new stack();
    int operationUsers;
    while(true)
    {
        std::cout<<"Выведите номер операции:\n 0) выход\n 1) работа со cтеком\n 2) работа со строкой текста\n"; std::cin>>operationUsers;
        if(operationUsers==0) break;

        if(operationUsers==1)
        {
            while(true)
            {
                std::cout<<"Введите номер операции над стеком:\n 0) выход\n 1) внесте сроку текста\n 2) вывод стека\n 3) удалить стек\n 4) поиск по индексу\n"; std::cin>>operationUsers;
                if(operationUsers==0) break;
                if(operationUsers==1)
                {
                    //text ** uesrsText; int i=1;
                    int number=0;
                    //char * str=(char*)malloc(1000* sizeof(char));
                    std::cout<<"Введите количество строк number=";std::cin>>number;
                    //uesrsText=(text**)malloc(number* sizeof(text*));
                    //for(int i=0; i<number; ++i) uesrsText[i]=(text*)malloc(sizeof(text));
                    //for(int i=0; i<number; ++i) {std::cin>>str; *uesrsText[i]= str;}
                    //for(int i=0; i<number; ++i) a->add(uesrsText[i],i+1);
                    // why not?
                    for(int i=0;i<number; i++) {
                        char *str=(char*)malloc(100*sizeof(char));
                        std::cin>>str;
                        text *str2 = new text(str);
                        a->add(str2, i+1);
                        //delete str2;
                        //free(str);
                    }
                }
                if(operationUsers==2) a->print();
                if(operationUsers==3) a->destroyed();
                if(operationUsers==4)
                {
                    int pos=0;
                    std::cout<<"Введите позицию position="; std::cin>>pos;
                    a->findOfPosition(pos)->str->getString(); std::cout<<"\n";
                }
            }
        }
        if(operationUsers==2)
        {
            while(true)
            {
                char * test=(char*)calloc(100, sizeof(char));
                char * test2=(char*)calloc(100, sizeof(char));
                char * buffer=(char*)calloc(100, sizeof(char));
                text text1;
                text text2;
                text result;
                std::cout<<"Введите номер операции над строкой текста:\n 0) выход\n 1) конкатенация строк\n 2) сравнение строк\n 3) длина строки\n 4) увеличение строки\n"; std::cin>>operationUsers;
                if(operationUsers==0) break;
                if(operationUsers==1)
                {
                    std::cout<<"\nВведите две строки текста (пробел (_)):\n";
                    std::cin>>test;
                    std::cin>>test2;
                    text1=test;
                    text2=test2;
                    result=text1+text2;
                    std::cout<<test<<"+"<<test2<<"="; result.getString();std::cout<<"\n";
                }
                if(operationUsers==2)
                {
                    std::cout<<"\nВведите две строки текста (пробел (_)):\n";
                    std::cin>>test;
                    std::cin>>test2;
                    text1=test;
                    text2=test2;
                    std::cout<<test<<">"<<test2<<"="<<(text1>text2)<<"\n";
                    std::cout<<test<<"<"<<test2<<"="<<(text1<text2)<<"\n";
                    std::cout<<test<<"=="<<test2<<"="<<(text1==text2)<<"\n";
                    std::cout<<test<<">="<<test2<<"="<<(text1>=text2)<<"\n";
                    std::cout<<test<<"<="<<test2<<"="<<(text1<=text2)<<"\n";
                    std::cout<<test<<"!="<<test2<<"="<<(text1!=text2)<<"\n";
                }
                if(operationUsers==3)
                {
                    std::cout<<"\nВведите две строки текста (пробел (_)):\n";
                    std::cin>>test;
                    std::cin>>test2;
                    text1=test;
                    text2=test2;
                    std::cout<<"length string1="<<text1.getLength();std::cout<<"\n";
                    std::cout<<"length string2="<<text2.getLength();std::cout<<"\n";
                }
                if(operationUsers==4)
                {
                    std::cout<<"\nВведите две строки текста (пробел (_)):\n";
                    std::cin>>test;
                    std::cin>>test2;
                    text1=test;
                    text2=test2;
                    text1+=text2;
                    std::cout<<"string1+=string2  =";text1.getString(); std::cout<<"\n";
                    std::cout<<"Ведите строку"; std::cin>>buffer;
                    text1+buffer;
                    std::cout<<"string1+char  =";text1.getString();std::cout<<"\n";
                }
            }
        }
    }
    return 0;
}

