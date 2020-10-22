#ifndef SERIAL_H_
#define SERIAL_H_

#define FOSC 16000000
#define BAUD 38400
#define MYUBRR ((FOSC/16)/BAUD)-1

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "led.h"

void uart_init(unsigned int);

void uart_putchar(char chr);

void uart_putstr(const char *str);

char uart_getchar(void);

void uart_echo(void);

void uart_getstr();

#endif

