/*

Name:  DUGGESH MP
RollNo:  24319005

Problem statement: STEPPER MOTOR

*/



#include<lpc214x.h>

void delay_ms(unsigned int count)
{
	unsigned int i=0,j=0;
	for(j=0;j<count;j++)
	{
		for(i=0;i<3000;i++);
	}
}
			
int main()
{
	PINSEL0=0x0000;	// CONFIGURE GPIO //
	PINSEL2=0x0000;
	IODIR0=0x0F ;	  // TO MAKE PINS-P0.0- P0.3 AS OUTPUT PINS //
	IODIR1=(0x0F) << 16 ;	// TO MAKE PINS-P1.16- P1.19 AS OUTPUT PINS //
	
	
	while(1)
	{
		IOSET0=0x01;   // LOGIC HIGH OR LED ON-LED at P0.0 //
		delay_ms(50);
		IOSET0=0x02; // LOGIC HIGH OR LED ON-LED at P0.1 //
		delay_ms(50);
		IOSET0=0x04; // LOGIC HIGH OR LED ON-LED at P0.2 //
		delay_ms(50);
		IOSET0=0x08; // LOGIC HIGH OR LED ON-LED at P0.3 //
		delay_ms(50);
		
		IOSET1=0x01 << 16;   // LOGIC HIGH OR LED ON-LED at P1.16 //
		delay_ms(50);
		IOSET1=0x02 <<16; // LOGIC HIGH OR LED ON-LED at P1.17 //
		delay_ms(50);
		IOSET1=0x04<<16; // LOGIC HIGH OR LED ON-LED at P1.18 //
		delay_ms(50);
		IOSET1=0x08<<16; // LOGIC HIGH OR LED ON-LED at P1.19 //
		delay_ms(50);
		
		IOCLR1=0x08 << 16;   // LOGIC LOW OR LED OFF at P1.19 //
		delay_ms(50);
		IOCLR1=0x04  << 16;   // LOGIC LOW OR LED OFF at P1.18 //
		delay_ms(50);
		IOCLR1=0x02  << 16;   // LOGIC LOW OR LED OFF at P1.17 //
		delay_ms(50);
		IOCLR1=0x01  << 16;   // LOGIC LOW OR LED OFF at P1.16 //
		delay_ms(50);
		
		IOCLR0=0x08;   // LOGIC LOW OR LED OFF at P0.3 //
		delay_ms(50);
		IOCLR0=0x04;   // LOGIC LOW OR LED OFF at P0.2 //
		delay_ms(50);
		IOCLR0=0x02;   // LOGIC LOW OR LED OFF at P0.1 //
		delay_ms(50);
		IOCLR0=0x01;   // LOGIC LOW OR LED OFF at P0.0 //
		delay_ms(50);
	}
}