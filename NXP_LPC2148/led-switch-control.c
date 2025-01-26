/********************************************************/
/* This Program is to demonstrate the LED and Push Button Functionality */
/*******************************************************
Author 		: Duggesh M P
Board 		: arm 7
Processor 	: LPC2148

Switch Mapping 	: Switch : P0.0
LED Mapping 	: LED0 : P0.1


Jumper Settings :

********************************************************/

#include <lpc214x.h>

char switchstatus;

int main(void)
{
	PINSEL0 = 0x00000000;
	IO0DIR &= 0xFFFFFFFE;  // P0.0 - Switch
	IO0DIR |= 0x00000002;  // P0.1 - LED
	
	while(1)
	{
		switchstatus = (IOPIN0 & 0x01);  // 0x00 - Switch Unpressed and 0x01 - Switch Pressed
		if(switchstatus == 1)
		{
			IOSET0 |= 0x00000002;
		}
		else
		{
			IOCLR0 |= 0x00000002;
		}
		
	}
	
}