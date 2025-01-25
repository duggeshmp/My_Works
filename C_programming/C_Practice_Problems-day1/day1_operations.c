#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#include "day1_head.h"

char  Ucase_To_Lcase(const char upper)
{
    printf("%c",upper);
    char lower = upper + 32;
   printf(" %c\n",lower);
    return lower;
}

double Area_Of_Circle(const float radius)
{
    float pi = 3.142;
    return pi*radius*radius;
}

int No_Of_Char_bw_2Char(const char letter1,const char letter2)
{
    int return_value=0;

    if((((letter1>=65)&&(letter1<=90))&&((letter2>=65)&&(letter2<=90)))||(
       ((letter1>=97)&&(letter1<=122))&&((letter2>=97)&&(letter2<=122))))
    {
        if(letter1>letter2) return_value = letter1-letter2-1;
        else return_value = letter2-letter1-1;


    }
    /*if(((letter1>=97)&&(letter1<=122))&&((letter2>=97)&&(letter2<=122)))
    {
        if(letter1>letter2) return_value = letter1-letter2-1;
        else return_value = letter2-letter1-1;
    }*/

    printf("\n %d",return_value);
    return return_value;
}

float Temp_Celsi_To_Fahren(const float celsius)
{
    return ((1.8)*celsius)+32;
}


int No_Is_Even_Odd(const int num)
{
    if(0 == num % 2) return 0;

    return 1;
}

int Is_Leap_Year(const unsigned int year)
{
    if((year % 4 == 0)&&((year % 400 == 0)||(year % 100 != 0))) return 0;

    return 1;

}

int Two_Power(const unsigned int power)
{
    return 1<<power;
}

int Check_Num_Or_Char(const char input)
{
    if((48 <= input) && (57 >= input)) return 1;

    return 0;
}

int Sum_Of_2_Rand_Num()
{
    int num1 = rand();
    int num2 = rand();

    printf("\n %d %d ",num1,num2);
    return num1 + num2 ;
}
