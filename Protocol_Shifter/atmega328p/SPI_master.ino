#include <avr/io.h>
#include <util/delay.h>

#define u8 unsigned char
#define s8 char
#define s16 int
#define u16 unsigned int
#define s32 long int
#define u32 long unsigned int


void SPI_MasterInit()
 {
    // Set MOSI and SCK as output, others as input
    DDRB = (1<<DDB3)|(1<<DDB5)|(1<<DDB2); // MOSI, SCK, and SS as output
    PORTB |= (1<<PB2); // Set SS high

    // Enable SPI, set as Master, set clock rate f_osc/16
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData) {
    // Start transmission by writing data to SPDR
    SPDR = cData;
    
    // Wait for transmission complete
    while(!(SPSR & (1<<SPIF)));
}

void SPI_MasterTransmitString(const char *str) {
    while (*str) {
        SPI_MasterTransmit(*str++);  // Send each character
        _delay_ms(10);               // Small delay for stability
    }
    SPI_MasterTransmit('\0');         // Send null character to indicate end of string
}

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

void UART_transmit(u8 data) 
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = data;
}

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

int main(void) {
      USART_Init(103);
    SPI_MasterInit(); // Initialize SPI as master

    while (1) {
        PORTB &= ~(1<<PB2); // Pull SS low to select slave
        transmit_string("SPI DATA transmitted : ");
       
        SPI_MasterTransmit(0x42);
        _delay_ms(100);
      
         UART_transmit(0x42);
         UART_transmit('\n');

        _delay_ms(1000); // Wait 1 second

        PORTB |= (1<<PB2); // Pull SS high to deselect slave
    }

    return 0;
}
