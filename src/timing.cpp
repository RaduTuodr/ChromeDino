#include "timing.h"
#include <util/delay.h>

void delay_ms_variable(uint16_t ms)
{
    while (ms--) {
        _delay_ms(1);
    }
}
