#ifndef __TIMER_H
#define __TIMER_H

#include "C8051F020.h"
#include "sys.h"

#define TIMER0_RELOAD_HIGH       AUX4  // Reload value for Timer0 high byte
#define TIMER0_RELOAD_LOW        AUX3  // Reload value for Timer0 low byte
#define SYSCLK    11059200

#define TIMER_PRESCALER            12  // Based on Timer CKCON settings

#define LED_TOGGLE_RATE            100 // LED toggle rate in milliseconds    1ms
                                       // if LED_TOGGLE_RATE = 1, the LED will
                                       // be on for 1 millisecond and off for
                                       // 1 millisecond

// There are SYSCLK/TIMER_PRESCALER timer ticks per second, so
// SYSCLK/TIMER_PRESCALER/1000 timer ticks per millisecond.
#define TIMER_TICKS_PER_MS  SYSCLK/TIMER_PRESCALER/1000

// Note: LED_TOGGLE_RATE*TIMER_TICKS_PER_MS should not exceed 65535 (0xFFFF)
// for the 16-bit timer

#define AUX1     TIMER_TICKS_PER_MS*LED_TOGGLE_RATE
#define AUX2     -AUX1
#define AUX3     AUX2&0x00FF
#define AUX4     ((AUX2&0xFF00)>>8)

void Timer0_Init(void);
void TIM1_Init(void);

#endif
