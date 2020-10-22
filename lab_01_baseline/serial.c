#include "serial.h"

void uart_init(unsigned int ubrr) {
	/*
		Baud rate is set with registers UBRR0H and UBRR0L
		Transmitting and receiving is enabled with UCSR0B register

		8n1 is set by default, here i am setting it anyway
		The USBS0 bit sets the frame to 1 or 2 stop bits but since USBS0 bit is supposed to be 0 for 1 stop bit i will leave it as is
		UPMn1:0 sets two bits, one bit that enables parity and one that sets the type of parity. Leaving this as is aswell
		UCSR0C register sets the number of bits to 8 in the frame
	*/
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1 << TXEN0) | (1 << RXEN0);

	UCSR0C = (3 << UCSZ00);
}

void uart_putchar(char chr) {
	/*
		Wait for empty transmit buffer
		Put data into buffer, sends the data
		If char is \n, send a \r after
	*/
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = chr;

	if (chr == '\n') {
		uart_putchar('\r');
	}
}

void uart_putstr(const char* str) {
	/*
		Print each char until char array null terminates AKA is empty
	*/
	for (int i = 0; str[i] != '\0'; i++) {
		uart_putchar(str[i]);
	}
}

char uart_getchar(void) {
	/*
		Waits for data to be received
		Get and return received data from buffer 
	*/
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void uart_echo(void) {
	/*
		Receive char from serial with uart_getchar, transmit char through serial with uart_putchar
	*/
	uart_putchar(uart_getchar());
}

void uart_getstr() {
	/*
		Reads chars from buffer and add to char array
		until char is \n, \r or aslong as index is below 10
		Null terminates char array
	*/
	int index = 0;
	int charArraySize = 10;
	char localChar = uart_getchar();
	char localCharArray[charArraySize];

	while (localChar != '\n' && localChar != '\r' && index < 10) { 
		localCharArray[index] = localChar;						  
		localChar = uart_getchar();
		index++;
	}
	localCharArray[index] = '\0'; 
	switchLedOnCommand(localCharArray);
}