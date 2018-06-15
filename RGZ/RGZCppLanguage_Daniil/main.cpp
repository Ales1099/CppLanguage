#include <iostream>
#include "date.h"
#include "double_list.h"
int main() {
    int opeartion_user=0;// i=1;
    date today=date(1,1,1);
    double_list<date> a(today,0);
    while(true)
    {
        std::cout<<"Работа со списком:\n 0) выход\n 1) внести элементы в список\n 2) респечатать список\n 3) удаление списка\n 4) поиск по позиции\n";
        std::cin>>opeartion_user;
        if(opeartion_user==0) break;
        if(opeartion_user==1)
        {
            int number=0,i=1;
            std::cout<<"Введите количсетво дат numbers"; std::cin>>number;
            while(number!=0) {
                int day, month, year;
                std::cout << "Введите день месяц и год через пробел: ";
                std::cin >> day >> month >> year;
                date date1 = date(day, month, year);
                a.add_new_element(date1, i);
                ++i;
                --number;
            }
        }
        if(opeartion_user==2) a.display();
        if(opeartion_user==3) a.clearn();
        if(opeartion_user==4) { int pos; std::cout<<"Введите позицию: "; std::cin>>pos; a.find_position(pos).print_date(); }
    }

    while (true)
    {
        std::cout<<"Работа с типом date:\n 0) выход\n 1) вперёд в будущее\n 2) назад в прошлое\n 3) сравнение двух дат\n"; std::cin>>opeartion_user;
        if(opeartion_user==0) break;
        if(opeartion_user==1)
        {
            date date1=a.find_position(1);
            date date2=a.find_position(2);
            date result;
            date1.print_date();std::cout<<"+"; date2.print_date(); std::cout<<"="; result=date1+date2; result.print_date();std::cout<<"\n";
            date1.print_date(); std::cout<<"++"; date1++; date1.print_date();std::cout<<"\n";
            std::cout<<"++";date2.print_date(); ++date2; date2.print_date();std::cout<<"\n";
            date1.print_date(); std::cout<<"+="; date2.print_date(); date1+=date2; date1.print_date();std::cout<<"\n";
            int number; std::cout<<"Введите номер number="; std::cin>>number;std::cout<<"\n";
            date1.print_date(); std::cout<<"+"<<number; date1+number; date1.print_date();std::cout<<"\n";
        }
        if(opeartion_user==2)
        {
            date date1=a.find_position(1);
            date date2=a.find_position(2);
            date result;
            date1.print_date();std::cout<<"-"; date2.print_date(); std::cout<<"="; result=date1-date2; result.print_date();std::cout<<"\n";
            date1.print_date(); std::cout<<"--"; date1--; date1.print_date();std::cout<<"\n";
            std::cout<<"--";date2.print_date(); --date2; date2.print_date();std::cout<<"\n";
            date1.print_date(); std::cout<<"-="; date2.print_date(); date1-=date2; date1.print_date();std::cout<<"\n";
            int number; std::cout<<"Введите номер number="; std::cin>>number;std::cout<<"\n";
            date1.print_date(); std::cout<<"-"<<number; date1-number; date1.print_date();std::cout<<"\n";
        }
        if(opeartion_user==3)
        {
            date date1=a.find_position(1);
            date date2=a.find_position(2);
            date1.print_date();std::cout<<"<"; date2.print_date(); std::cout<<"="<<(date1<date2)<<"\n";
            date1.print_date(); std::cout<<">"; date2.print_date(); std::cout<<"="<<(date1>date2)<<"\n";
            date1.print_date(); std::cout<<"<="; date2.print_date(); std::cout<<"="<<(date1<=date2)<<"\n";
            date1.print_date(); std::cout<<">="; date2.print_date(); std::cout<<"="<<(date1>=date2)<<"\n";
            date1.print_date(); std::cout<<"=="; date2.print_date(); std::cout<<"="<<(date1==date2)<<"\n";
            date1.print_date(); std::cout<<"!="; date2.print_date(); std::cout<<"="<<(date1!=date2)<<"\n";
        }
    }
    system("pause");
    return 0;
}

