#include <lpc214x.h>

#define RS (1 << 11) // P0.2
#define E  (1 << 12) // P0.1
#define LCD_PORT (0xFC) // P0.3 to P0.10 (8-bit mode)

void UART0_Init(void) {
    PINSEL0 |= 0x00000005; // Set P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;           // 8 bits, no Parity, 1 Stop bit
    U0DLL = 97;             // Set baud rate to 9600 (assuming 12MHz clock)
    U0DLM = 0;              // (Divisor = 12MHz / 9600)
    U0LCR = 0x03;           // Disable DLAB
}

char UART0_ReceiveChar(void) {
    while (!(U0LSR & 0x01)); // Wait for RDR to be set
    return U0RBR;            // Return received character
}

void LCD_Command(unsigned char cmd) {
	volatile int i;
    IO0CLR = LCD_PORT;       // Clear data pins
    IO0SET = cmd;            // Send command
    IO0CLR = RS;             // Select command register
    IO0SET = E;              // Enable LCD
    for (i = 0; i < 1000; i++); // Delay
    IO0CLR = E;              // Disable
}

void LCD_Init(void) {
	volatile int i;
    IO0DIR |= LCD_PORT | RS | E; // Set LCD pins as output
    LCD_Command(0x38);       // 8-bit mode, 2 lines, 5x8 dots
    LCD_Command(0x0C);       // Display ON, Cursor OFF
    LCD_Command(0x06);       // Increment cursor
    LCD_Command(0x01);       // Clear display
    for ( i = 0; i < 2000; i++); // Delay
}

void LCD_DisplayChar(char ch) {
	volatile int i;
    IO0CLR = LCD_PORT;       // Clear data pins
    IO0SET = ch;             // Send character
    IO0SET = RS;             // Select data register
    IO0SET = E;              // Enable LCD
    for (i = 0; i < 1000; i++); // Delay
    IO0CLR = E;              // Disable
}

void main(void) {
	char receivedChar;
    UART0_Init();
   
    
	 LCD_Init();
	receivedChar = 'h';
	LCD_DisplayChar(receivedChar);

    while (1) {
        receivedChar = UART0_ReceiveChar(); // Wait for a character
        LCD_DisplayChar(receivedChar);       // Display on LCD
    }
}
