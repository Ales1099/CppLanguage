#include <iostream>
#include <math.h>
#include <time.h>
#include "list.h"
#include "BigDecimal.h"

int main() {
    setlocale(LC_ALL,"RUS");
    BigDecimal bigInt = BigDecimal((unsigned char*)"467364");
    list<BigDecimal> a(bigInt);
    int operationUsers,i=1;
    std::cout<<"Work with list\n";
    while(true)
    {
        std::cout<<"\n0) exit\n1) enter the numbers\n2) print the list\n3) destroyed the list\n4) find the number for its position\n"; std::cin>>operationUsers;
        if(operationUsers==0) break;
        if(operationUsers==1)
        {
            int numbers=0;
            std::cout<<"Enter product quantity. numbers="; std::cin>>numbers;
            while (numbers!=0)
            {
                BigDecimal bigDecimal;
                unsigned char * buffer;
                buffer = (unsigned char*)calloc(100, sizeof(unsigned char));
                std::cin>>buffer;
                bigDecimal= BigDecimal(buffer);
                a.add(bigDecimal,i);
                ++i;
                --numbers;
            }
        }
        if(operationUsers==2) a.print();
        if(operationUsers==3) a.clearn();
        if(operationUsers==4)
        {
            int pos=0;
            std::cout<<"Enter the position. pos="; std::cin>>pos;
            a.find(pos).write();
        }
    }
    std::cout<<"Work with the very large numbers\n";
    while (true)
    {
        std::cout<<"\n0) exit\n1) total\n2) difference\n3) multiplication\n4) compare\n"; std::cin>>operationUsers;
        if(operationUsers==0) break;
        if(operationUsers==1)
        {
            BigDecimal bigDecimal1, bigDecimal2, result, resultq;
            bigDecimal1=a.find(1).getNum();
            //bigDecimal1.setNumBits(123);
            bigDecimal2=a.find(2).getNum();
            bigDecimal1.write();std::cout<<"+";bigDecimal2.write();std::cout<<"=";result=bigDecimal1+bigDecimal2;result.write();std::cout<<"\n";
            std::cout<<"++";bigDecimal1.write();std::cout<<"=";++bigDecimal1; bigDecimal1.write();std::cout<<"\n";
            bigDecimal2.write();std::cout<<"++";std::cout<<"=";bigDecimal2++; bigDecimal2.write();std::cout<<"\n";
            bigDecimal1.write();std::cout<<"+=";
            bigDecimal2.write();std::cout<<"=";
            bigDecimal1+=bigDecimal2;
            bigDecimal1.write();std::cout<<"\n";
        }
        if(operationUsers==2)
        {
            BigDecimal bigDecimal1, bigDecimal2, result;
            bigDecimal1=a.find(1).getNum();
            bigDecimal2=a.find(2).getNum();
            bigDecimal1.write();std::cout<<"-";bigDecimal2.write();std::cout<<"=";result=bigDecimal1-bigDecimal2;result.write();std::cout<<"\n";
            std::cout<<"--";bigDecimal1.write();std::cout<<"=";--bigDecimal1; bigDecimal1.write();std::cout<<"\n";
            bigDecimal2.write();std::cout<<"--";std::cout<<"=";bigDecimal2--; bigDecimal2.write();std::cout<<"\n";
            bigDecimal1.write();std::cout<<"-=";bigDecimal2.write();bigDecimal1-=bigDecimal2;bigDecimal1.write();std::cout<<"\n";
        }
        if(operationUsers==3)
        {
            BigDecimal bigDecimal1, bigDecimal2, result;
            unsigned char*number; number=(unsigned char*)calloc(100, sizeof(unsigned char));
            bigDecimal1=a.find(1).getNum();
            bigDecimal2=a.find(2).getNum();
            bigDecimal1.write();std::cout<<"*";bigDecimal2.write();std::cout<<"=";result=bigDecimal1*bigDecimal2;result.write();std::cout<<"\n";
            bigDecimal1.write();std::cout<<"*=";bigDecimal2.write();bigDecimal1*=bigDecimal2;bigDecimal1.write();std::cout<<"\n";
            std::cout<<"Enter a number. number="; std::cin>>number;
            bigDecimal2.write(); std::cout<<"*"<<number<<"="; bigDecimal2*=number;std::cout<<"="; bigDecimal2.write();std::cout<<"\n";
        }
        if(operationUsers==4)
        {
            BigDecimal bigDecimal1, bigDecimal2, result;
            bigDecimal1=a.find(1).getNum();
            bigDecimal2=a.find(2).getNum();
            bigDecimal1.write();std::cout<<">";bigDecimal2.write();std::cout<<"="<<(bigDecimal1>bigDecimal2)<<"\n";
            bigDecimal1.write();std::cout<<"<";bigDecimal2.write();std::cout<<"="<<(bigDecimal1<bigDecimal2)<<"\n";
            bigDecimal1.write();std::cout<<"==";bigDecimal2.write();std::cout<<"="<<(bigDecimal1==bigDecimal2)<<"\n";
            bigDecimal1.write();std::cout<<"!=";bigDecimal2.write();std::cout<<"="<<(bigDecimal1!=bigDecimal2)<<"\n";
            bigDecimal1.write();std::cout<<">=";bigDecimal2.write();std::cout<<"="<<(bigDecimal1>=bigDecimal2)<<"\n";
            bigDecimal1.write();std::cout<<"<=";bigDecimal2.write();std::cout<<"="<<(bigDecimal1<=bigDecimal2)<<"\n";
            std::cout<<"!";bigDecimal2.write();std::cout<<"="<<(!bigDecimal2)<<"\n";
        }
    }
    system("pause");
    return 0;
}


