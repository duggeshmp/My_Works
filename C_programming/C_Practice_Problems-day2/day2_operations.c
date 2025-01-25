#include "day2_head.h"

int Sum_Of_Digits_Of_Num(int input_num)
{
    int sum = 0;
    printf("\n%d ",input_num);
    while(input_num > 0)
    {
        sum = sum + (input_num % 10 );
        input_num = input_num / 10;
    }

    return sum;
}

unsigned int Reverse_Num(unsigned int input_num)
{
    unsigned int reverse_num = 0;

    while(input_num > 0)
    {
        reverse_num = reverse_num *10;
        reverse_num += input_num % 10;
        input_num = input_num / 10;
    }

    return reverse_num;
}

unsigned int Occur_Of_Digit(unsigned int input_num,const unsigned int check_digi)
{
    unsigned int occur_num = 0;
    while(input_num > 0)
    {
        if(check_digi == input_num % 10) occur_num++ ;

        input_num = input_num / 10 ;
    }
    return occur_num;
}

int Is_Num_Palindrome(const unsigned int input_num)
{
    unsigned int revers_num = Reverse_Num(input_num);

    if (input_num == revers_num) return SUCCESS;
    return FAILURE;
}

int Is_Prime(const int input_num)
{
    for(int i = 2; i <= input_num/2 ; i++)
        if(input_num % i == 0) return FAILURE;

    return SUCCESS;
}

void First_N_Prime_Num(unsigned int num)
{
        for(int i = 2 ;num != 0 ;i++)
            if(0 == Is_Prime(i))
        {
            printf("\n %d",i);
            num--;
        }
}

unsigned int Sum_Of_Pattern(unsigned int input_length)
{
    unsigned int sum = 0,series = 0;

    while(input_length != 0)
    {
        series = series * 10;
        series += 1;
        sum += series;
        input_length--;
    }
    return sum;
}
unsigned int Num_Of_Digis_In_Num(int input_num)
{
    unsigned int digits = 0;
    while(input_num != 0)
    {
        input_num = input_num/10 ;
        digits++ ;
    }
    return digits;
}

int Is_Armstrong_Num(const unsigned int input_num)
{
    unsigned int sum = 0, var = 0,n_of_digits=0;

    var = input_num ;
    n_of_digits = Num_Of_Digis_In_Num(input_num);

    while(var != 0)
    {
        sum += pow((var % 10),n_of_digits);
        var = var/10 ;
    }
    if(input_num == sum) return SUCCESS;

    return FAILURE;
}

int Is_Num_Pair_Amicable(const int num1,const int num2)
{
    unsigned int sum_of_factors1 = 0,sum_of_factors2 = 0;

    for(int i=1 ;i <= num1/2 ; i++)
        if(num1 % i == 0) sum_of_factors1 += i;

    for(int i=1 ;i <= num2/2 ; i++)
        if(num2 % i == 0) sum_of_factors2 += i;

    if((num2 == sum_of_factors1)&&(num1 == sum_of_factors2)) return SUCCESS;

    return FAILURE;

}

int Menue_Driven(const int num1,const int num2,const int operation)
{
    switch(operation)
    {
        case 1 : return num1 + num2 ;
        case 2 : if(num1>num2) return num1-num2;
                 return num2 - num1;
        case 3 : return num1 * num2;
        default : break;
    }

    return FAILURE;
}

void Volume_Of_Cuboid(const unsigned int length,const unsigned int breadth,const unsigned int height)
{
    if((length == breadth)&&(breadth == height)) printf("\n Volume of cube = %d ",length*breadth*height);
    else printf("\n Volume of cuboid %d ",length*breadth*height);
}

void Volume_Of_Sphere(const unsigned int radius)
{
     printf("\n Volume of Sphere %f ",(4/3)*(PI*radius*radius*radius));
}

void Volume_Of_Cylinder(const unsigned int radius,const unsigned int height)
{
    printf("\n Volume of cylinder %f ",(PI*radius*radius*height));
}

void Volume_Of_Cone(const unsigned int radius,const unsigned int height)
{
    float volume = (PI*radius*radius*height)/3;
    printf("\nVolume of cone %f " ,volume);
}

unsigned int Electricity_Bill(const unsigned int num_of_units)
{
    if(num_of_units <= 200)
        return num_of_units*5;

    if((num_of_units>200)&&(num_of_units<=300))
        return (200*5)+((num_of_units % 200) * 7);

    return (200*5)+(100*7)+((num_of_units-300)*10);
}
