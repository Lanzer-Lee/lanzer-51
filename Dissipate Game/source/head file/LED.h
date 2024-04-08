#ifndef __LED_H
#define __LED_H

#include "C8051F020.h"
#include "sys.h"
#include "delay.h"
#include "GAME.h"

#define LED_NUM P7
#define LED_NUM_0   0xC0
#define LED_NUM_1   0xF9
#define LED_NUM_2   0xA4
#define LED_NUM_3   0xB0
#define LED_NUM_4   0x92
#define LED_NUM_5   0x82
#define LED_NUM_6   0xF8
#define LED_NUM_7   0x80
#define LED_NUM_8   0x90
#define LED_NUM_9   0x88
#define LED_NUM_10  0x83
#define LED_NUM_11  0xC6
#define LED_NUM_12  0xA1
#define LED_NUM_13  0x86
#define LED_NUM_14  0x8E
#define LED_NUM_15  0xC0
#define LED_SELECT_H P5
#define LED_SELECT_L P6
#define LED_BIT 4

//void led_init(void);
void led_display_num(uint8_t number);
void led_select(uint8_t order);
void led_dispaly(void);

#endif