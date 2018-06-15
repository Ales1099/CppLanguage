//
// Created by Ales1098 on 31.05.2018.
//

#include "BigDecimal.h"

BigDecimal::BigDecimal(unsigned char *number)
{
    this->bigNumber=number;
    this->lengthOfBigNumber=length(number);
}

BigDecimal::BigDecimal()
{
    bigNumber=(unsigned char*)calloc(100,sizeof(unsigned char));
    lengthOfBigNumber=0;
}

void BigDecimal::write()
{
    std::cout<<bigNumber;
}
int BigDecimal::length(unsigned char *number)
{
    int length=0;
    for(length;*(number+length)!='\0'; ++length);
    return length;
}
/*Логические операторы*/
bool const BigDecimal::operator>(const BigDecimal &num)
{
    bool pointer1=false, pointer2=false;
    if((*this).lengthOfBigNumber > num.lengthOfBigNumber) pointer1=true;
    for(int i=0; i<(*this).lengthOfBigNumber; i++)
    {
        if(int(*((*this).bigNumber+i))>int(*(num.bigNumber+i))) pointer2= true;
        else
        {
            pointer2= false;
            break;
        }
    }
    return pointer1 || pointer2;
}

bool const BigDecimal::operator<(const BigDecimal &num)
{
    bool pointer1=false, pointer2=false;
    if((*this).lengthOfBigNumber < num.lengthOfBigNumber) pointer1=true;
    for(int i=0; i<(*this).lengthOfBigNumber; i++)
    {
        if(int(*((*this).bigNumber+i)) < int(*(num.bigNumber+i))) pointer2= true;
        else
        {
            pointer2= false;
            break;
        }
    }
    return pointer1 || pointer2;
}

bool const BigDecimal::operator==(const BigDecimal &num)
{
    bool pointer1=false, pointer2=false;
    if((*this).lengthOfBigNumber == num.lengthOfBigNumber) pointer1=true;
    for(int i=0; i<(*this).lengthOfBigNumber; i++)
    {
        if(int(*((*this).bigNumber+i)) == int(*(num.bigNumber+i))) pointer2= true;
        else
        {
            pointer2= false;
            break;
        }
    }
    return pointer1 && pointer2;
}

bool const BigDecimal::operator<=(const BigDecimal &num)
{
    return ((*this)<num || (*this)==num);
}

bool const BigDecimal::operator>=(const BigDecimal &num)
{
    return (*this)>num || (*this)==num;
}

bool const BigDecimal::operator!=(const BigDecimal &num)
{
    if((*this)==num) return false;
    return true;
}

bool const BigDecimal::operator!()
{
    if((*this)==(*this)) return false;
    return true;
}
/*Арифметичесие операторы*/

//сложение
BigDecimal operator+(const BigDecimal &num1, const BigDecimal &num2)
{
    int maxSizeOfBigNumber = (num1.lengthOfBigNumber >= num2.lengthOfBigNumber ? num1.lengthOfBigNumber : num2.lengthOfBigNumber);
    unsigned char * result;
    result=(unsigned char*)calloc(maxSizeOfBigNumber+1,sizeof(unsigned char));
    memset(result,'0',(maxSizeOfBigNumber+1));
    unsigned char dx, dy;
    int t=0, d=0;
    for(int i=0; i<maxSizeOfBigNumber; ++i)
    {
        dx = (i < num2.lengthOfBigNumber) ? *(num2.bigNumber + num2.lengthOfBigNumber - i - 1) : 0;
        dy = (i < num1.lengthOfBigNumber) ? *(num1.bigNumber + num1.lengthOfBigNumber - i - 1) : 0;
        dx <<= 4;
        dx >>= 4;
        dy <<= 4;
        dy >>= 4;
        t = dx + dy + d;
        d = t / 10;
        *(result + i) = t % 10 + '0';
    }
    BigDecimal res;
    if(d==1)
    {
        *(result+maxSizeOfBigNumber)='1';
        maxSizeOfBigNumber=maxSizeOfBigNumber+1;
    }
    unsigned char * buffer;
    buffer=(unsigned char*)calloc(maxSizeOfBigNumber,sizeof(unsigned char));
    memset(buffer,'0',maxSizeOfBigNumber);
    for(int i=0; i<maxSizeOfBigNumber; i++) *(buffer+i)=*(result+maxSizeOfBigNumber-i-1);
    memcpy(res.bigNumber,buffer,maxSizeOfBigNumber);
    free(result);
    free(buffer);
    return res;

}

BigDecimal BigDecimal::operator+=( BigDecimal right)
{
    return (*this)=(*this)+right;
}

BigDecimal BigDecimal::operator++(int)
{
    BigDecimal help=(*this);
    ++(*this);
    return help;
}

BigDecimal BigDecimal::operator++()
{
    BigDecimal help;
    help = BigDecimal((unsigned char*)"1");
    return (*this)=(*this)+help;
}
//вычитание
BigDecimal operator-(const BigDecimal &num1, const BigDecimal &num2)
{
    int * result, *bufferInt, parametr=0,m=0;
    unsigned char dx,dy;
    unsigned char * buffer;

    int maxSize = num1.lengthOfBigNumber > num2.lengthOfBigNumber ? num1.lengthOfBigNumber : num2.lengthOfBigNumber ;
    result = (int*)calloc(maxSize+1, sizeof(int));

    for(int i=maxSize-1; i>=0; --i)
    {
        dx = i < num1.lengthOfBigNumber ? *(num1.bigNumber+num1.lengthOfBigNumber-i-1) : 0;
        dy = i < num2.lengthOfBigNumber ? *(num2.bigNumber+num2.lengthOfBigNumber-i-1) : 0;
        dx <<= 4;
        dx >>= 4;
        dy <<= 4;
        dy >>= 4;
        *(result+i)=dx-dy;
    }

    for(int i=0; i<maxSize-1; ++i)
    {
        if(*(result+i)>=0);
        else
        {
            *(result+i)+=10;
            *(result+i+1)-=1;
        }
    }

    for(int i=maxSize-1; i>=0; --i) { if(*(result+i)==0) ++m; else break; }

    parametr=maxSize-m;
    bufferInt=(int*)malloc(parametr* sizeof(int));
    for(int i=0; i<parametr; ++i) *(bufferInt+i)=*(result+i);
    buffer=(unsigned char*)calloc(maxSize, sizeof(unsigned char));
    BigDecimal res;
    if(parametr==0) res.bigNumber=(unsigned char*)"0";
    else
    {
        int t = 0;
        for (int i = parametr - 1; i >= 0; ++t, --i) *(buffer + t) = *(bufferInt + i) + '0';
        memcpy(res.bigNumber,buffer,(size_t)parametr);
    }

    free(result);
    free(bufferInt);
    free(buffer);
    return res;
}

BigDecimal BigDecimal::operator-=(const BigDecimal &num)
{
    (*this)=(*this)-num;
    return (*this);
}

BigDecimal BigDecimal::operator--()
{
    unsigned char * one = (unsigned char*)"1";
    BigDecimal help=one;
    (*this)-=help;
    return (*this);
}

BigDecimal BigDecimal::operator--(int)
{
    BigDecimal help=(*this);
    --(*this);
    return help;
}
//умножение
BigDecimal operator*(const BigDecimal &num1, const BigDecimal &num2)
{

    int maxSizeOfBigNumber = (num1.lengthOfBigNumber >= num2.lengthOfBigNumber ? num1.lengthOfBigNumber : num2.lengthOfBigNumber);
    int minSizeOfBigNumber = (num1.lengthOfBigNumber <= num2.lengthOfBigNumber ? num1.lengthOfBigNumber : num2.lengthOfBigNumber);
    int sizeResult = maxSizeOfBigNumber+minSizeOfBigNumber;

    int * result;
    result = (int*)malloc(sizeResult* sizeof(int));
    unsigned char dx,dy;
    int t=0,d=0, p=1;

    for(int i=0; i<sizeResult; i++) *(result+i)=0;

    for(int i=0; i<minSizeOfBigNumber; ++i)
    {
        for(int j=0; j<maxSizeOfBigNumber; ++j)
        {
            dx = ((i < num2.lengthOfBigNumber) ? *(num2.bigNumber + num2.lengthOfBigNumber - i - 1 ) : 1);
            dy = ((j < num1.lengthOfBigNumber) ? *(num1.bigNumber + num1.lengthOfBigNumber - j - 1 ) : 1);
            dx <<= 4;
            dx >>= 4;
            dy <<= 4;
            dy >>= 4;
            *(result+i+j)+=dx*dy;
        }
    }

    for(int i=0; i<sizeResult-1; ++i)
    {
        *(result+i+1)+=(*(result+i)/10);
        *(result+i)=*(result+i)%10;
    }

    if(*(result+sizeResult-1)==0) p=2;

    BigDecimal res;
    for(int i=sizeResult-p; i>=0;++t, --i) *(res.bigNumber+t)=*(result+i)+'0';
    free(result);
    return res;
}

BigDecimal BigDecimal::operator*=(const BigDecimal &num)
{
    return (*this)=(*this)*num;
}

BigDecimal BigDecimal::operator*(unsigned char *number)
{
    BigDecimal help = number;
    (*this)*=help;
    return (*this);
}

BigDecimal::operator int() {
    int * buffer;
    buffer=(int*)malloc((*this).lengthOfBigNumber);
    for(int i=0; i<(*this).lengthOfBigNumber; ++i)
    {
        *((*this).bigNumber+i) <<= 4;
        *((*this).bigNumber+i) >>= 4;
        *(buffer+i) = (*this).bigNumber[i];
    }
    return *buffer;
}

BigDecimal::operator bool() {
    if((*this)!= BigDecimal((unsigned char*)"0")) return true;
    return false;
}

BigDecimal::operator unsigned char () {
    return *(*this).bigNumber;
}

unsigned char* BigDecimal::getNum() {
    return this->bigNumber;
}

BigDecimal BigDecimal::operator+(unsigned char *number) {
    BigDecimal help = number;
    (*this)+=help;
    return (*this);
}

BigDecimal BigDecimal::operator-(unsigned char *number) {
    BigDecimal help = BigDecimal(number);
    (*this)-=help;
    return (*this);
}

BigDecimal BigDecimal::operator=(BigDecimal number) {
    this->bigNumber=number.bigNumber;
    this->lengthOfBigNumber=length(number.bigNumber);
    return (*this);
}


