#include <lpc214x.h>
#include <math.h>

void uart_init()
{
	PINSEL0 = 0X05;
	
	U0LCR = 0x83;//DLATCH BIT ENEABLE 1 STOPBIT 8 BIT DATA
	U0DLM = 0X00;
	U0DLL = 97;
	U0LCR = 0x03;
}

void pll_init()
{
	PLL0CON = 0x01;
	PLL0CFG = 0X24;
	PLL0FEED = 0XAA;
	PLL0FEED = 0X55;
	while(PLL0STAT & (1<<10) == 0);
	PLL0CON = 0x03;
	VPBDIV = 0x01;
	PLL0FEED = 0XAA;
	PLL0FEED = 0X55;
}
void delay_us(unsigned int delay)
{
	T0CTCR = 0x00;
	T0TCR = 0x02;
	T0PR = 59;
	T0TCR = 0x01;
	
	while(T0TC < delay);
	
	T0TCR = 0x00;
}
void analogwrite( int data)
{
	DACR = data<<6;
}

void sendchar(char data)
{
	while((U0LSR & 0x20) == 0);
	U0THR = data;
}
void sendstring(char str[])
{
	int i = 0;
	while(str[i] != '\0'){
	sendchar(str[i]);
		i++;
}
}
int main()
{
	int i;
	double sineval;
	pll_init();
	uart_init();
	
	sendstring("ART AND DAC\n");
	/*for(i = 0;i < 100;i++){
		analogwrite(i*10);
		delay_us(100);
	}
	while(1);*/

	while(1){
	/*//for(i = 0;i < 50;i++){
		analogwrite(1023);
		delay_us(100);
	//}
	//
	//for(i = 50;i > 0;i--){
		analogwrite(00);
		delay_us(100);
	//}*/

		for(i = 1;i< 180;i++)
		{
			sineval =sin((i*2*3.142)/360);
			if(sineval < 0) sineval = 1+sineval;
			analogwrite(sineval*1023);
			//delay_us(100);
		}
		for(i = 270;i< 360;i++)
		{
			sineval =sin((i*2*3.142)/360);
			if(sineval < 0) sineval = 1+sineval;
			analogwrite(sineval*1023);
			//delay_us(100);
		}
		for(i = 90;i< 80;i++)
		{
			sineval =sin((i*2*3.142)/360);
			if(sineval < 0) sineval = 1+sineval;
			analogwrite(sineval*1023);
			//delay_us(100);
		}
		
}
	
}

