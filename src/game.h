#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#define AVTduino_ROWS 2
#define AVTduino_COLS 16

#define PLAYER_COL 2
#define PLAYER_CHAR '&'
#define BLOCK_CHAR 0xFF

extern uint8_t player_row;
extern uint8_t jump_timer;
extern uint16_t score;
extern uint8_t game_over;
extern uint16_t game_delay;

void game_init(void);
void game_update(uint8_t button);

#endif
