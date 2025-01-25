#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#include "day1_head.h"
int main()
{
    printf("Hello world!\n");

        assert(Ucase_To_Lcase('A') == 'a');
        assert(Ucase_To_Lcase('D') == 'd');
        assert(Ucase_To_Lcase('X') == 'x');
        assert(Ucase_To_Lcase('W') == 'w');
        assert(Ucase_To_Lcase('S') == 's');

    printf("area of circles having radius 2,5,9.5,1.75 and 7.77 respectively are \n %f \n%f \n%f \n%f \n%f",
            Area_Of_Circle(2),Area_Of_Circle(5),Area_Of_Circle(9.5),Area_Of_Circle(1.75),Area_Of_Circle(7.77));


        assert(No_Of_Char_bw_2Char('A','D') == 2);
        assert(No_Of_Char_bw_2Char('K','D') == 6);
        assert(No_Of_Char_bw_2Char('A','Z') == 24);
        assert(No_Of_Char_bw_2Char('u','m') == 7);
        assert(No_Of_Char_bw_2Char('p','x') == 7);
        assert(No_Of_Char_bw_2Char('y','d') == 20);

    printf("\nFahrenheit temp value of celsius temperatures 5,38,25.6,17.7 are \n %f %f %f %f",
           Temp_Celsi_To_Fahren(5),Temp_Celsi_To_Fahren(38),Temp_Celsi_To_Fahren(25.6),Temp_Celsi_To_Fahren(17.7));

        assert(No_Is_Even_Odd(2)   == 0);
        assert(No_Is_Even_Odd(9)   == 1);
        assert(No_Is_Even_Odd(227) == 1);
        assert(No_Is_Even_Odd(0)   == 0);
        assert(No_Is_Even_Odd(16)  == 0);
        assert(No_Is_Even_Odd(228) == 0);
        assert(No_Is_Even_Odd(827) == 1);

        assert(Is_Leap_Year(100)  == 1);
        assert(Is_Leap_Year(84)   == 0);
        assert(Is_Leap_Year(2012) == 0);
        assert(Is_Leap_Year(2024) == 0);
        assert(Is_Leap_Year(3000) == 1);
        assert(Is_Leap_Year(1947) == 1);

        assert(Two_Power(3)  == 8);
        assert(Two_Power(10) == 1024);
        assert(Two_Power(0)  == 1);
        assert(Two_Power(6)  == 64);
        assert(Two_Power(1)  == 2);
        assert(Two_Power(8)  == 256);

        assert(Check_Num_Or_Char('9') == 1);
        assert(Check_Num_Or_Char('0') == 1);
        assert(Check_Num_Or_Char('5') == 1);
        assert(Check_Num_Or_Char('*') == 0);
        assert(Check_Num_Or_Char('a') == 0);
        assert(Check_Num_Or_Char('#') == 0);

        printf("\n Sum of two random numbers %d %d %d %d ",Sum_Of_2_Rand_Num(),Sum_Of_2_Rand_Num(),
                                                            Sum_Of_2_Rand_Num(),Sum_Of_2_Rand_Num());

    return 0;
}
