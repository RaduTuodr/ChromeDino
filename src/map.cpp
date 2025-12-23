#include "map.h"
#include <stdlib.h>

uint8_t map[AVTduino_ROWS][AVTduino_COLS + 1];

void init_map(void)
{
    for (uint8_t r = 0; r < AVTduino_ROWS; r++) {
        for (uint8_t c = 0; c < AVTduino_COLS; c++)
            map[r][c] = ' ';
        map[r][AVTduino_COLS] = '\0';
    }
}

void shift_map(void)
{
    for (uint8_t c = 0; c < AVTduino_COLS - 1; c++) {
        map[0][c] = map[0][c + 1];
        map[1][c] = map[1][c + 1];
    }
    map[0][AVTduino_COLS - 1] = ' ';
    map[1][AVTduino_COLS - 1] = ' ';
}

void spawn_obstacles(void)
{
    int value = rand();

    if (value % 20 == 0)
        map[1][AVTduino_COLS - 1] = BLOCK_CHAR;

    if (score > 250 && value % 51 == 0)
        map[0][AVTduino_COLS - 1] = BLOCK_CHAR;
}
