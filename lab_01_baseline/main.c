#define FOSC 16000000
#define BAUD 38400
#define MYUBRR ((FOSC/16)/BAUD)-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "serial.h"
#include "led.h"

int main() {
    uart_init(MYUBRR);
    while (1) {
        uart_echo();
    }
    return 0;
}