#define FOSC 16000000
#define BAUD 38400
#define MYUBRR ((FOSC/16)/BAUD)-1

#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"
#include "led.h"

int main() {
    uart_init(MYUBRR);
    while (1) {
        uart_putstr("David Kristensson\n");
        _delay_ms(1000);
    }
    return 0;
}