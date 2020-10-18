#define FOSC 1843200 // Clock Speed
#define BAUD 38400
#define MYUBRR ((FOSC/16)/BAUD)-1

#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main() {
    uart_init(MYUBRR);

    /* 
    //Sätter index 1-3 i DDRB registret (motsvarar pin 9-11) till 1 med OR
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);

    while (1) {
        //Tänder LED genom att OR:a in 1 i PORTB registret
        PORTB |= (1 << PB1);
        _delay_ms(50);
        //Släcker LED genom att NOR:a in 0 i PORTB registret
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
    */

    return 0;
}