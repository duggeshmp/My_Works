/*

Name: DUGGESH MP 
RollNo: 24319005

Problem statement: STEPPER MOTOR clock wise

*/




#include<lpc214x.h>
void delay(void);
int main(void)
{
	PINSEL0 = 00;        // SELECT PIN AS GPIO
	IODIR0 =(0xF<<4);  //SET PORT DIRECTION P0.4-P0.7 AS OUTPUT
	
	IO0DIR &= ~(1<<9);		// Configure P0.9 as input
	IO0DIR &= ~(1<<10);		// Configure P0.10 as input
	IO0DIR &= ~(1<<11);		// Configure P0.11 as input
	while(1)
	{
		if ((IO0PIN & (1 << 9)) ) 
        {
						IOCLR0=0xC0;
						IOSET0=0x30;   //0011
						delay();
						
						IOCLR0=0x90;    //0110
						IOSET0=0x60;
						delay();
						
						IOCLR0=0x30;    //1100
						IOSET0=0xC0;
						delay();
						
						IOCLR0=0x60;    //1001
						IOSET0=0x90;
						delay();

										
        }
				if ((IO0PIN & (1 << 10)) ) 
        {
						IOCLR0=0x90;    //0110
						IOSET0=0x60;
						delay();
					
						IOCLR0=0xC0;
						IOSET0=0x30;   //0011
						delay();
					
						IOCLR0=0x60;    //1001
						IOSET0=0x90;
						delay();
						
						IOCLR0=0x30;    //1100
						IOSET0=0xC0;
						delay();
												
        }
			if ((IO0PIN & (1 << 11))) // Switch is pressed then making led output 0
        {
						IOCLR0=0x30;
						IOCLR0=0x90;
						IOCLR0=0x60;
						IOCLR0=0x30; 
				}

		
		
		

		
	}
}

void delay(void)        //delay function
{
	int a;
	for(a=0;a<=100000;a++)
	{};
}
		
		
