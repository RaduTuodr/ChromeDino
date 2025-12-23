#include <stdlib.h>

#include <avr/interrupt.h>
#include <util/delay.h>

#include "HD44780.hpp"
#include "libADC.hpp"

#include "game.h"
#include "input.h"
#include "render.h"
#include "timing.h"

int main(void)
{
    LCD_Initalize();
    ADC_Init();
    sei();

    srand(1);
    game_init();

    uint8_t last_button = 0;

    while (1) {
        uint8_t button = read_button();

        if (game_over) {
            render_game_over();
            if (button == 5)
                game_init();
            _delay_ms(150);
            continue;
        }

        game_update(button);

        last_button = button;
        
        render_game();

        delay_ms_variable(game_delay);
    }
}
