#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include <util/delay.h>

void led_init();
void led_flash();
void led_change(char* color, char* state);
void switchLedOnCommand(char* parsedStringFromUart);

#endif