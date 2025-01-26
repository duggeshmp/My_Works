/********************************************************/
/* This Program is to demonstrate the RELAY Functionality */
/*******************************************************
Author 		: Duggesh M P
						241039005
						
Board 		: arm 7
Processor 	: LPC2148

SWITCH Mapping  : P0.10 P0.11 P0.12

********************************************************/

#include<lpc214x.h>
#define bit(x) (1<<x)
#define delay for(i=0;i<=6000;i++)

unsigned int i;

int main()
{
    IO0DIR=0xf;                     //Declaring as a output
    IO0PIN=0;                           //Clear all IO Pins in P0
	
		IO0DIR &= ~(1<<10);		// Configure P0.9 as input
		IO0DIR &= ~(1<<11);		// Configure P0.10 as input
		IO0DIR &= ~(1<<12);		// Configure P0.11 as input
    VPBDIV=0x01;                    //PCLK = 60MHz
    while(1) {
			
			if((IO0PIN & (1 << 10)))
			{
				/*Forward*/
        IO0SET=bit(0);          //IN1 = 1
        IO0CLR=bit(1);          //IN2 = 0
        delay;delay;
			}
        if((IO0PIN & (1 << 11))){
				/*Reverse*/
        IO0SET=bit(1);          //IN2 = 1
        IO0CLR=bit(0);          //IN0 = 1
        delay;delay;
				}
        /*Off*/
        /*IO0CLR=bit(0)|bit(1); //IN1 = IN2 = 0
        delay;delay;*/
        if((IO0PIN & (1 << 11)))
				{
        /*Off*/
        IO0CLR=bit(0)|bit(1); //IN1 = IN2 = 0
        delay;delay;
				}
			}
}