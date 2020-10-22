#include "led.h"

void led_init() {
    /*
        PB1-3 indexes in DDRD registery are set to 1 AKA output
    */
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);
}

void led_change(char* color, char* state) {
    /*
        Using OR operator to set binary value 1 on index PB1-3 in register PORTB turns led on
        Using NAND operator to set binary value 0 on index PB1-3 in register PORTB turns led off
    */
    if (strcasecmp(state, "ON") == 0) {
        if (strcasecmp(color, "GREEN") == 0) {
            PORTB |= (1 << PB1);
        }
        else if (strcasecmp(color, "BLUE") == 0) {
            PORTB |= (1 << PB2);
        }
        else if (strcasecmp(color, "RED") == 0) {
            PORTB |= (1 << PB3);
        }
    }

    if (strcasecmp(state, "OFF") == 0) {
        if (strcasecmp(color, "GREEN") == 0) {
            PORTB &= ~(1 << PB1);
        }
        else if (strcasecmp(color, "BLUE") == 0) {
            PORTB &= ~(1 << PB2);
        }
        else if (strcasecmp(color, "RED") == 0) {
            PORTB &= ~(1 << PB3);
        }
    }
}

void led_flash() {
    /*
        This is where we party
    */
    while (1) {
        led_change("RED", "ON");
        _delay_ms(50);
        led_change("RED", "OFF");
        _delay_ms(50);

        led_change("GREEN", "ON");
        _delay_ms(50);
        led_change("GREEN", "OFF");
        _delay_ms(50);

        led_change("BLUE", "ON");
        _delay_ms(50);
        led_change("BLUE", "OFF");
        _delay_ms(50);
    }
}

void switchLedOnCommand(char* parsedStringFromUart) {
    /*
        Check if value of char array is on or off,
        change state of led thereafter
    */
    if (strcasecmp(parsedStringFromUart, "ON") == 0) {
        led_change("RED", "ON");
    }
    else if (strcasecmp(parsedStringFromUart, "OFF") == 0) {
        led_change("RED", "OFF");
    }
}
