#include "serial.h"

int main() { 
    led_init();
    uart_init(MYUBRR);

    while (1) {
        uart_getstr();
    }
    return 0;
}