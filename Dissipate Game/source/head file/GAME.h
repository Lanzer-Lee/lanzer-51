#ifndef __GAME_H
#define __GAME_H

#include "C8051F020.h"
#include "sys.h"
#include "KEY.h"
#include "lcd.h"
#include "delay.h"

#define BLOCK0 0x20
#define BLOCK1 0x02
#define BLOCK2 0x03
#define BLOCK3 0x04
#define BLOCK4 0x05
#define BLOCK_ACTIVE 0x06
#define LEVEL_LEN 17
#define CURSOR_ROW 3
#define CURSOR 0x18

extern uint8_t game_level4[];
extern uint8_t cursor;
extern uint8_t block[3][LEVEL_LEN];
extern uint8_t pad;
extern uint8_t score;

void set_cursor(uint8_t position);
void cursor_update(void);
void press_right_key(void);
void press_left_key(void);
void press_middle_key(void);
void block_scan(void);
void block_update(void);
//void auto_play(void);
void block_down(void);
void game_init(void);

//void auto_cursor(void);


#endif
