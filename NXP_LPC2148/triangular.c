/********************************************************/
/* Traingular waveform at 50hz using 100 samples
*******************************************************
Author 		: DUGGESH M P 241039005
						
						
						
Board 		: arm 7
Processor 	: LPC2148


DAC pin P0.25

********************************************************/


#include <lpc214x.h>
#include "delayus.h"

void analogwrite(unsigned int dacdata){
	DACR=dacdata<<6;
}
void pll()
{
	PLL0CFG=0X24; //P=4(2 bits), M=2(5 bits)
	PLL0CON=0X01;  //enable PLL
	PLL0FEED=0XAA;  //feed sequence
	PLL0FEED=0X55;  //feed sequence
	while((PLL0STAT & (1<<10))==0);      //wait for PLL to latch on target freq
	PLL0CON=0X03;   //enable & connect PLL
	PLL0FEED=0XAA;    //feed sequence
	PLL0FEED=0X55; 
	
	VPBDIV=0X01;   
}
void delay_us(unsigned int us) {
    T0TCR = 0x02;  // Reset Timer
    T0PR  = 59;    // Prescaler for 1 microsecond (PCLK 60 MHz, 60 ticks per us)
    T0TCR = 0x01;  // Enable Timer

		while (T0TC < us);
    /*while (us > 0) {
        // Wait until Timer reaches the match value
        while (T0TC < us);  
        T0TC = 0;  // Reset the timer counter
        us--;      // Decrement the us count
    }*/

    T0TCR = 0x00;  // Disable Timer
}

int main(){
	int i;
	pll();
	PINSEL1 |= (0x2 << 18); //pin 0.25 as DAC
	
	while(1)
	{
		for(i=0;i<50;i++){
			analogwrite(i*20);
			delay_us(1000);
		}
		//delay_us(200);
		for(i=0;i<50;i++){
			analogwrite(1000-(i*20));
			delay_us(1000);
		}
		//delay_us(200);
	}
} 