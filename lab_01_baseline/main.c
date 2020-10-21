#define FOSC 16000000
#define BAUD 38400
#define MYUBRR ((FOSC/16)/BAUD)-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "serial.h"
#include "led.h"

int main() {
    char uartInput[10];
    //char* ledInput = "";
    led_init();
    uart_init(MYUBRR);
    int i = 0;
    while (1) {
        switchLed(uartInput, i);
    }
    return 0;
}