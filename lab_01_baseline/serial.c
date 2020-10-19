#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

void uart_init(unsigned int ubrr) {
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	// Enable transmitter
	UCSR0B = (1 << TXEN0);
}

void uart_putchar(char chr) {
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1 << UDRE0)));
	// Put data into buffer, sends the data
	UDR0 = chr;

	if (chr == '\n') { // If char is \n, send a \r after
		uart_putchar('\r');
	}
}

void uart_putstr(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) { //Run loop until string is empty
		uart_putchar(str[i]); //Print each char in char array
	}
}