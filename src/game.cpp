#include "game.h"
#include "map.h"

const uint8_t SPEEDUP_RATE = 3;
const uint8_t SPEED_START = 200;
const uint8_t SPEED_MIN = 120;

uint8_t player_row = 1;
uint8_t jump_timer = 0;
uint16_t score = 0;
uint8_t game_over = 0;
uint16_t game_delay = 200;

static uint16_t max(uint16_t a, uint16_t b)
{
    return (a > b) ? a : b;
}

void game_init(void)
{
    score = 0;
    game_over = 0;
    player_row = 1;
    jump_timer = 0;
    game_delay = 200;
    init_map();
}

void game_update(uint8_t button)
{
    if (game_over)
        return;

    if (button == 2 && jump_timer == 0)
        jump_timer = 3;

    game_delay = max(SPEED_START - score / SPEEDUP_RATE, SPEED_MIN);

    shift_map();
    spawn_obstacles();

    if (jump_timer > 0) {
        jump_timer--;
        player_row = 0;
    } else {
        player_row = 1;
    }

    if (map[player_row][PLAYER_COL] == BLOCK_CHAR) {
        game_over = 1;
        return;
    }

    score++;
}
