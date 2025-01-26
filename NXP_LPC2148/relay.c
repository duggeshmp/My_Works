/********************************************************/
/* This Program is to demonstrate the RELAY Functionality */
/*******************************************************
Author 		: Duggesh M P
						241039005
						
Board 		: arm 7
Processor 	: LPC2148

relay Mapping  : P0.0

********************************************************/
#include<lpc214x.h>
#define bit(x) (1<<x)
//#define delay for(i=0;i<60000;i++)
/******************************USER DEFINED FUNCTION************************************/
void delay()
{
	unsigned int i;
	for(i=0;i<60000;i++);
}
/*pin0.0 is used to controle relay switch*/
int main()
{
    IO0DIR=0xff; 
    IO0PIN=0;

    while(1) {
        IO0SET=bit(0);       //Relay ON
        delay();
        IO0CLR=bit(0);              //Relay OFF
        delay();
    }
}