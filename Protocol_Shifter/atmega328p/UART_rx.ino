#include <avr/io.h>
#include<util/delay.h>
/*
// UART Register Addresses
// USART Register Addresses
#define UBRR0H  *((volatile uint8_t *)0xC5)  // USART Baud Rate Register High
#define UBRR0L  *((volatile uint8_t *)0xC4)  // USART Baud Rate Register Low
#define UCSR0A  *((volatile uint8_t *)0xC0)  // USART Control and Status Register A
#define UCSR0B  *((volatile uint8_t *)0xC1)  // USART Control and Status Register B
#define UCSR0C  *((volatile uint8_t *)0xC2)  // USART Control and Status Register C
#define UDR0    *((volatile uint8_t *)0xC6)  // USART Data Register (Transmit/Receive)


// Bit positions in UCSR0A (Control and Status Register A)
#define RXC0   7  // USART Receive Complete flag
#define TXC0   6  // USART Transmit Complete flag
#define UDRE0  5  // USART Data Register Empty flag
#define FE0    4  // Frame Error flag
#define DOR0   3  // Data OverRun flag
#define UPE0   2  // USART Parity Error flag
#define U2X0   1  // Double the USART Transmission Speed flag (not used for standard baud rate)
#define MPCM0  0  // Multi-processor Communication Mode

// Bit positions in UCSR0B (Control and Status Register B)
#define RXCIE0 7  // USART Receive Complete Interrupt Enable
#define TXCIE0 6  // USART Transmit Complete Interrupt Enable
#define UDRIE0 5  // USART Data Register Empty Interrupt Enable
#define RXEN0  4  // USART Receiver Enable
#define TXEN0  3  // USART Transmitter Enable
#define UCSZ02 2  // Character Size bit 2 (combined with UCSZ00, UCSZ01)
#define RXB8   1  // Receive Data Bit 8
#define TXB8   0  // Transmit Data Bit 8


// Bit positions in UCSR0C (Control and Status Register C)
#define UCSZ01 1  // Character Size bit 1
#define UCSZ00 2  // Character Size bit 0
#define UPM01  5  // Parity Mode bit 1
#define UPM00  4  // Parity Mode bit 0
#define USBS0  3  // Stop Bit Select
#define UCPOL0 0  // Clock Polarity (used for synchronous mode)
*/

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#define u8 unsigned char
#define s8 char
#define s16 int
#define u16 unsigned int
#define s32 long int
#define u32 long unsigned int

void USART_Init(u16 ubrr);

void UART_transmit(u8 data);

u8 UART_receive(void); 

/**********************************
 * Function = USART_Init()
 * 
 * input =ubrr(16bit UART Baud Rate value)
 * 
 * UCSR0B = USART Control and Status Register n B
 * 
 * UCSR0C = USART Control and Status Register n C
 * 
 * 
 * *********************************/

void USART_Init(u16 ubrr)
{
/*Set baud rate */
UBRR0H = (u8)(ubrr>>8);
UBRR0L = (u8)ubrr;

/*Enable receiver and transmitter */
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0) | (1 << TXCIE0) | (1 << RXCIE0);

/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

/**********************************
 * Function = USART_Transmit()
 * 
 * Function to transmit a single character
 * 
 * input =8 bit data which need to be sent
 * 
 * UDRE0: USART Data Register Empty(6th bit of UCSR0A)
 * 			1 = empty buffer
 *	 		0 = unempty buffer
 * 
 * UCSR0C = USART Control and Status Register n A
 * 
 * 
 * *********************************/
void UART_transmit(u8 data) 
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = data;
}

/**********************************
 * Function = UART_receive()
 * 
 * Function to recive a single character
 * 
 * 
 * RXC0: USART Receive Complete(8th bit of UCSR0A)
 * 		 1 = unempty buffer
 * 		 0 = empty buffer
 * 
 * UCSR0A = USART Control and Status Register n A
 * 
 * 
 * *********************************/
u8 UART_receive(void) {

    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)));

    // Get and return received data from buffer
    return UDR0;
}
/***********************************************************/
void transmit_string(u8 string1[])
{
  u8 i =0;
     while(NULL != string1[i])
    {
      
      UART_transmit(string1[i]);
      i++;
      _delay_ms(10);
    }
}
/***********************************************************************/
int main()
{
	USART_Init(103);
  UART_transmit('1');
  UART_transmit('h');
    UART_transmit('e');
    UART_transmit('l');
    UART_transmit('l');
    UART_transmit('o');
     UART_transmit('\n');
	while(1)
	{	
		
		_delay_ms(10);
    
   UART_transmit(UART_receive());

	}

	return 0;
}