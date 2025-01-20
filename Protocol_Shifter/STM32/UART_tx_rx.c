#include "stm32f10x.h"

void uart_init()
{
	
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;//ENABLING CLOCK FOR UART1 14th bit
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;


	GPIOA->CRH &= ~0x00000FF0;//reseting port A
	GPIOA->CRH |= GPIO_CRH_MODE9_0;//0x00000010
	GPIOA->CRH |= GPIO_CRH_CNF9_1;
	
	GPIOA->CRH &= ~GPIO_CRH_CNF10;
	GPIOA->CRH |= GPIO_CRH_CNF10_0;
	GPIOA->CRH &= ~GPIO_CRH_MODE10 ;
	
	USART1->BRR = 0x1D4C;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_TE;
	//USART1->CR1 |= USART_CR1_TCIE;
	//USART1->CR1 |= USART_CR1_RXNEIE;
	USART1->CR1 |= USART_CR1_UE;
	
	}
void delay(int delay){
	int i;
	for(;delay>0;delay-- )
	for(i = 0; i < 100000; i++){
	}
}
void uart_sendchar(char data){
	
	while(!(USART1->SR & USART_SR_TXE));
		USART1->DR = data;
}

void uart_transmit(char string1[])
{
	char i =0;
     while('\0' != string1[i])
    {
      
      uart_sendchar(string1[i]);
      i++;
      delay(10);
    }
		delay(10);
	}



char uart_receive()
{
	while(!(USART1->SR & USART_SR_RXNE));
	
	return USART1->DR;

}



int main()
{
	char receiv = 0;;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= ~0xFFFFFFF0;
	GPIOB->CRL |=  0x00000003;
	GPIOB->ODR |= 0x0001;
	//	delay();
	uart_init();
	

	while(1)
	{
		delay(100);
	
		uart_transmit("Hello\n");
		//receiv = uart_receive();
		//uart_sendchar(uart_receive());
		
		//delay();
		
		
	
	}
	
	
	
}

