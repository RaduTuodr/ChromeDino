#include "input.h"
#include "libADC.hpp"
#include "uart_buffer.hpp"
#include <avr/io.h>

uint16_t raw;

uint8_t read_button(void)
{
    ADCSRA |= (1<<ADSC);
    while (ADCSRA & (1<<ADSC));
    raw = ADC;

    if (raw < 100) return 1;
    else if (raw < 250) return 2;
    else if (raw < 350) return 3;
    else if (raw < 550) return 4;
    else if (raw < 800) return 5;
    else return 0;
}
