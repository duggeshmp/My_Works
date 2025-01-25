/************************  STANDARD HEADER FILES DECLARATION  **************************************/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<assert.h>

#define SUCCESS 0
#define FAILURE 1
#define PI 3.1415
/*------------------------------------------------------------------------------------------------------------
                                     USER DEFINED FUNCTIONS
--------------------------------------------------------------------------------------------------------------*/
/**************************************************************************************************************

Function :- Sum_Of_Digits_Of_Num()

input = 5 digit number

output/return = sum of digits of input number i.e example 12356 -> 17

Note : Input should not be starting with zero i.e 01247 is invalid input
**************************************************************************************************************/

int Sum_Of_Digits_Of_Num(int);

/**************************************************************************************************************

Function :- Reverse_Num()

input = positive integer

output/return = reverse of given number

Note : Input should not be starting with zero i.e 01247 is invalid input
**************************************************************************************************************/

unsigned int Reverse_Num(unsigned int);

/**************************************************************************************************************

Function :- Occur_Of_Digit()

input1 = positive integer
input2 = check number

output/return = number of times that given number present in input

Note : Input1 should not be starting with zero i.e 01247 is invalid input
**************************************************************************************************************/

unsigned int Occur_Of_Digit(unsigned int,unsigned int);

/**************************************************************************************************************

Function :- Is_Num_Palindrome()

input = positive integer to check palindrome

output/return = returns 0 for palindrome,
                        1 for non palindrome

Note : Input should not be starting with zero i.e 01247 is invalid input
**************************************************************************************************************/

int Is_Num_Palindrome(const unsigned int);

/**************************************************************************************************************

Function :- Is_Prime()

checks whether given integer is prime or not

input = integer

output/return = returns 0 for prime number,
                        1 for composite number

**************************************************************************************************************/

int Is_Prime(const int);

/**************************************************************************************************************

Function :- First_N_Prime_Num()

gives first n prime numbers print

input = integer

output/return = prime number prints

**************************************************************************************************************/

void First_N_Prime_Num(unsigned int num);

/**************************************************************************************************************

Function :- Sum_Of_Pattern()

 To find the sum of the series 1,11,111,....111 up to n.
For eg. if n=4, the series is: 1+11+111+1111 = 1234

input = integer i.e length of serise

output/return = sum of number of series

**************************************************************************************************************/

unsigned int Sum_Of_Pattern(const unsigned int);
/**************************************************************************************************************

Function :- Num_Of_Digis_In_Num()

calculates number of digits in a input number

input = unsigned integer number

output/return = returns number of digits

**************************************************************************************************************/

unsigned int Num_Of_Digis_In_Num(int);
/**************************************************************************************************************

Function :- Is_Armstrong_Num()

A number is called an Armstrong number if the sum of the cubes of the digits of the
number is equal to the number. For example 153 = 1^3 + 5^3 + 3^3
                                          1634 = 1^4 + 6^4 + 3^4 + 4^4

input = unsigned integer number

output/return = returns 0 for Armstrong numer
                        1 for non Armstrong number

**************************************************************************************************************/

int Is_Armstrong_Num(const unsigned int);

/**************************************************************************************************************

Function :- Is_Num_Pair_Amicable()

Amicable numbers are found in pairs. A given pair of numbers is Amicable if the sum
of the proper divisors (not including itself) of one number is equal to the other number
and vice – versa.
For example 220 & 284 are amicable numbers. First we find the proper divisors of
220:
220:1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110; 1+ 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55+ 110 = 284
Now, 284: 1, 2, 4, 71, 142; 1 + 2 + 4 + 71 + 142 = 220

input = pairs of integer

output/return = returns 0 for Amicable numer
                        1 for non Amicable number

**************************************************************************************************************/

int Is_Num_Pair_Amicable(const int,const int);

/**************************************************************************************************************

Function :- Menue_Driven()

calculates number of digits in a input number

input 1 = integer number
input 2 = integer number
input 3 = operations to be performed
            1 = sum
            2 = difference
            3 = product

output/return = the result of operation chosen by user,


**************************************************************************************************************/

int Menue_Driven(const int,const int,const int);

/**************************************************************************************************************

Function :- Volume_Of_Cuboid()

calculates volume of cuboid or cube shape i.e volume = l*b*h

input 1 = length of shape
input 2 = breadth of shape
input 3 = height of shape

output/return = Displays the volume of shape


**************************************************************************************************************/

void Volume_Of_Cuboid(const unsigned int,const unsigned int,const unsigned int);

/**************************************************************************************************************

Function :- Volume_Of_Sphere()

calculates volume of sphere shape i.e volume = 4/3(pi*r*r*r)

input  = Radius of the sphere


output/return = Displays the volume of sphere shape


**************************************************************************************************************/

void Volume_Of_Sphere(const unsigned int);

/**************************************************************************************************************

Function :- Volume_Of_Cylinder()

calculates volume of Cylinder shape i.e volume = pi*r*r*h

input 1 = Radius of the Cylinder
input 2 = height of the Cylinder


output/return = Displays the volume of Cylinder shape


**************************************************************************************************************/

void Volume_Of_Cylinder(const unsigned int,const unsigned int);

/**************************************************************************************************************

Function :- Volume_Of_Cone()

calculates volume of cone shape i.e volume = pi*r*r*h

input 1 = Radius of the cone
input 2 = height of the cone


output/return = Displays the volume of cone shape


**************************************************************************************************************/

void Volume_Of_Cone(const unsigned int,const unsigned int);

/**************************************************************************************************************

Function :- Electricity_Bill()

calculates Electricity bill based on following rates
    For the First 200 units : Rs 5 per unit
    For the next 100 units : Rs7 per unit
    Beyond 300 units : Rs 10 Per unit

input  = Number of units consumed

output/return = returns electricity charges for consumed units


**************************************************************************************************************/

unsigned int Electricity_Bill(const unsigned int);
