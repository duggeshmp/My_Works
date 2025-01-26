#include <lpc214x.h>

void UART0_Init(void) {
    PINSEL0 |= 0x00000005; // Set P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;           // 8 bits, no Parity, 1 Stop bit
    U0DLL = 97;             // Set baud rate to 9600 (assuming 12MHz clock)
    U0DLM = 0;              // (Divisor = 12MHz / 9600)
    U0LCR = 0x03;           // Disable DLAB
}

void UART0_SendChar(char ch) {
    while (!(U0LSR & 0x20)); // Wait for the THR to be empty
    U0THR = ch;              // Send the character
}

int main(void) {
	
		int i;
	volatile int j;
   
    char message[] = "Hello, LPC2148 #2!\n";
	 UART0_Init();

    while (1) {
        for (i = 0; message[i] != '\0'; i++) {
            UART0_SendChar(message[i]); // Send each character
        }
        for ( j = 0; j < 1000000; j++); // Delay
    }
		
		return 0;
}
