/************************  STANDARD HEADER FILES DECLARATION  **************************************/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<assert.h>

#define SUCCESS 0
#define FAILURE 1
#define ROW     3
#define COLUMN  3
#define PI 3.1415
/*------------------------------------------------------------------------------------------------------------
                                     USER DEFINED FUNCTIONS
--------------------------------------------------------------------------------------------------------------*/

/**************************************************************************************************************

Function :- Binary_2_Decimal()

input = Binary format input in unsigned integer form
            dont start input with zero (Because it considers it as octal number)

output/return = returns Decimal value of binary
**************************************************************************************************************/
int Binary_2_Decimal(unsigned int);

/**************************************************************************************************************

Function :- Sequence_Generator1()
Generate a sequence of numbers such that every number in the sequence is the sum of the previous three numbers.
 The first three numbers are 0,0,1.

input = number of elements in the sequence

output/return = prints sequence
**************************************************************************************************************/
void Sequence_Generator1(unsigned int);

/**************************************************************************************************************

Function :- Sequence_Generator2()

to print the following sketch with input N as number of rows
* * * *
  * * *
    * *
      *
input = number of rows

output/return = prints sequence
**************************************************************************************************************/
void Sequence_Generator2(unsigned int);

/**************************************************************************************************************

Function :- Sequence_Generator3()

To Generate the following sequence using a single loop with N as number of rows*
*
* *
* * *
* * * *
input = number of rows

output/return = prints sequence
**************************************************************************************************************/
void Sequence_Generator3(unsigned int);

