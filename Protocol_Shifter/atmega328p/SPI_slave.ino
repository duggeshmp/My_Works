#include <avr/io.h>
#include <avr/interrupt.h>

#define u8 unsigned char
#define s8 char
#define s16 int
#define u16 unsigned int
#define s32 long int
#define u32 long unsigned int

volatile char receivedData = 0;

void SPI_SlaveInit(void) {
    // Set MISO as output
    DDRB = (1<<DDB4); // MISO as output
    SPCR = (1<<SPE);  // Enable SPI in slave mode
    //sei();            // Enable global interrupts
}
/*
ISR(SPI_STC_vect) {
    receivedData = SPDR;       // Read data from SPDR
    SPDR = receivedData + 1;   // Set SPDR with response (data + 1)
}*/

char SPI_SlaveReceive()
{
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)));
/* Return Data Register */
return SPDR;
}

void SPI_SlaveReceiveString(char *buffer, uint8_t bufferSize) {
    uint8_t i = 0;
    uint8_t receivedChar;

    while (i < bufferSize - 1) {
        receivedChar = SPI_SlaveReceive();  // Receive a byte
        if (receivedChar == '\0') {         // Check for end of string
            break;
        }
        buffer[i++] = receivedChar;         // Store character in buffer
    }
    buffer[i] = '\0';  // Null-terminate the received string
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

void UART_TransmitString(const char *str) {
    while (*str) {
        UART_transmit(*str++);
    }
}

int main(void) {

    USART_Init(103);
    SPI_SlaveInit(); // Initialize SPI as slave



    while (1) {

        // Continuously loop, SPI interrupt handles data reception
        UART_TransmitString("SPI DATA received : ");

        UART_transmit(SPI_SlaveReceive());
       UART_transmit('\n');
       _delay_ms(50);
    }

    return 0;
}
