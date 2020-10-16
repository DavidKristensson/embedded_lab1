#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main() {
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);

    while (1) {
        PORTB |= (1 << PB1);
        _delay_ms(50);
        PORTB &= ~(1 << PB1);
        _delay_ms(50);

        PORTB |= (1 << PB2);
        _delay_ms(50);
        PORTB &= ~(1 << PB2);
        _delay_ms(50);

        PORTB |= (1 << PB3);
        _delay_ms(50);
        PORTB &= ~(1 << PB3);
        _delay_ms(50);
    }

    return 0;
}