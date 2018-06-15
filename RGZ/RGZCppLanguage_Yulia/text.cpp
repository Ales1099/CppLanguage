//
// Created by Ales1098 on 02.06.2018.
//

#include <cstring>
#include "text.h"

text::text()
{
    stringOfText=(char*)malloc(1000* sizeof(char));
}

int text::getLength()
{
    return lengthOfStringText;
}
int text::textlen(char * stringUsers)
{
    int length=0;
    for(length; stringUsers[length] != '\0'; length++);
    return length;
}

bool text::corrected(char *stringOne, char *stringTwo)
{
    bool pointer;
    int maxLenth = textlen(stringOne) >= textlen(stringTwo) ? textlen(stringOne) : textlen(stringTwo);

    for(int i=0; i<maxLenth; i++)
    {
        if(*(stringOne+i) == *(stringTwo+i) ) pointer= true;
        else
        {
            pointer= false;
            break;
        }
    }

    return pointer;
}

text::text(char *stringusers)
{
    stringOfText=stringusers;
    lengthOfStringText=textlen(stringusers);
}

text operator+(text &stringOne, text &stringTwo)
{
    text result;
    result.stringOfText=(char*)calloc(100, sizeof(char));
    result.stringOfText=result.strcopipaste(stringOne.stringOfText,stringTwo.stringOfText);
    return result;
}

char *text::strcopipaste(char *one, char *two)
{
    char * buffer=(char*)malloc(sizeof(char));
    memcpy(buffer,one,textlen(one));
    for(int i=textlen(one); i<textlen(one)+textlen(two)+1; i++) buffer[i]=two[i-textlen(one)];
    return buffer;
}

text text::operator+=(text &stringUser)
{
    (*this)=(*this)+stringUser;
    return (*this);
}

bool const text::operator<(const text &stringOne)
{
    return (*this).lengthOfStringText < stringOne.lengthOfStringText ? true : false;
}

bool const text::operator>(const text &stringOne)
{
    return (*this).lengthOfStringText > stringOne.lengthOfStringText ? true : false;
}

bool const text::operator==(const text &stringOne)
{
    return corrected((*this).stringOfText,stringOne.stringOfText);
}

bool const text::operator>=(const text &stringOne)
{
    return ((*this)>stringOne || (*this)==stringOne);
}

bool const text::operator<=(const text &stringOne)
{
    return ((*this)<stringOne || (*this)==stringOne);
}

bool const text::operator!=(const text &stringOne)
{
    return !((*this)==stringOne);
}

text text::operator+(char *usersText) {
    text help = usersText;
    (*this)+=help;
    return (*this);
}


