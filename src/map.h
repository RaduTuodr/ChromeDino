#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include "game.h"

extern uint8_t map[AVTduino_ROWS][AVTduino_COLS + 1];

void init_map(void);
void shift_map(void);
void spawn_obstacles(void);

#endif
