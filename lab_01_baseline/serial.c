#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "serial.h"

void uart_init(unsigned int ubrr) {
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	// Enable transmitter & receiver
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
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
	for (int i = 0; str[i] != '\0'; i++) { // Run loop until string is empty
		uart_putchar(str[i]); // Print each char in char array
	}
}

char uart_getchar(void) {
	// Wait for data to be received
	while (!(UCSR0A & (1 << RXC0)));
	// Get and return received data from buffer 
	return UDR0;
}

void uart_echo(void) {
	// Get char from PC with uart_getchar, put that char from atmega to PC
	uart_putchar(uart_getchar());
}

void UARTgetStringTillEmpty() {
	//Så länge det finns tecken i input-buffern
	//	läs ut tecken och spara i char[]
}

void switchLed(char* uartInput, int i) {

	char localChar = uart_getchar();
	while (localChar != '\n' && localChar != '\r') {
		uartInput[i] = localChar;
		localChar = uart_getchar();
		i++;
		PORTB |= (1 << PB2);
		_delay_ms(100);
		PORTB &= ~(1 << PB2);
		_delay_ms(100);
		//PORTB |= (1 << PB3);
	}

	if (uartInput[0] == 'O') {
		if (uartInput[1] == 'N' && i > 0) {
			PORTB |= (1 << PB1);
			for (int i = 0; i < strlen(uartInput); i++) {
				uartInput[i] = 0;
				i = 0;
			}
		}
		else if (uartInput[1] == 'F' && i > 0) {
			if (uartInput[2] == 'F' && i > 1) {
				PORTB &= ~(1 << PB1);
				for (int i = 0; i < strlen(uartInput); i++) {
					uartInput[i] = 0;
					i = 0;
				}
			}
		}
	}

	//uart_putstr(uartInput);

	/*
	for (int i = 0; i < 3; i++) {
		char localChar = uart_getchar();
		uartInput[i] = localChar;
	}
	*/
	
	/*
	char localChar = uart_getchar();
	while (localChar != '\n' || localChar != '\r') {
		uartInput[i] = localChar;

		if (uartInput[0] == 'O') {
			if (uartInput[1] == 'N' && i > 0) {
				PORTB |= (1 << PB1);
				for (int i = 0; i < strlen(uartInput); i++) {
					uartInput[i] = 0;
					i = 0;
				}
			}
			else if (uartInput[1] == 'F' && i > 0) {
				if (uartInput[2] == 'F' && i > 1) {
					PORTB &= ~(1 << PB1);
					for (int i = 0; i < strlen(uartInput); i++) {
						uartInput[i] = 0;
						i = 0
					}
				}
			}
		}

		localChar = uart_getchar();
		i++;
		
	}
	PORTB |= (1 << PB2);
	//for (int i = 0; i < strlen(uartInput); i++) {
	//	uartInput[i] = 0;
	//}
	*/
	
	/*
	if (strcmp(uartInput, "NO") == 0) {
		PORTB |= (1 << PB1);
		strcpy(uartInput, "");
	}

	*/
	/*
	if (uart_getchar() == 'Y') {
		PORTB |= (1 << PB1);
	}
	else if (uart_getchar() == 'N') {
		PORTB &= ~(1 << PB1);
	}
	*/

	/*
	strncat(ledInput, uart_putchar, 1);

	uart_putstr(ledInput);

	if (strcmp(ledInput, "ON\n\r") == 0) {
		PORTB |= (1 << PB1);
		strcpy(ledInput, "");
	}
	*/
}