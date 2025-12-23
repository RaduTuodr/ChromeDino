#include "render.h"
#include "game.h"
#include "map.h"
#include "HD44780.hpp"
#include <stdlib.h>
#include <string.h>

void render_game(void)
{
    LCD_GoTo(0, 0);
    LCD_WriteText((char*)map[0]);

    LCD_GoTo(0, 1);
    LCD_WriteText((char*)map[1]);

    LCD_GoTo(PLAYER_COL, player_row);
    LCD_WriteData(PLAYER_CHAR);
}

void render_game_over(void)
{
    LCD_Clear();
    LCD_GoTo(0, 0);
    LCD_WriteText("Game over! P:");

    char buff[7];
    itoa(score, buff, 10);
    LCD_GoTo(strlen("Game over! P:"), 0);
    LCD_WriteText(buff);

    LCD_GoTo(0, 1);
    LCD_WriteText("Retry? SEL");
}
