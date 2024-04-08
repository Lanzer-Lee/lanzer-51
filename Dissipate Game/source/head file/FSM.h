#ifndef __FSM_H
#define __FSM_H

#include "C8051F020.h"
#include "sys.h"
#include "KEY.h"
#include "GAME.h"
//#include "1.h"
//#include "2.h"
//#include "3.h"
#define STATE0_0    0
#define STATE0_1    1
#define STATE0_2    2
#define STATE_1     3
#define STATE_2     4
#define STATE_3     5

extern uint8_t state;

void open_device_display(void);
void state_init(void);
void state_transfer(void);
void state_run(void);

#endif
