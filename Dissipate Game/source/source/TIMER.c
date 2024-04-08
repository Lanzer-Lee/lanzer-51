#include "TIMER.h"

void Timer0_Init(void)
{
	TH0 = TIMER0_RELOAD_HIGH;           // Reinit Timer0 High register
	TL0 = TIMER0_RELOAD_LOW;
	ET0 = 1;                            // Timer0 interrupt enabled
	TMOD = 0x01;                        // 16-bit Mode Timer0
	//TCON |= 0x10;                        // Timer0 ON
}
/*
void TIM1_Init(void){
    TMOD&=0xF0;
    TMOD|=0x02;
    TL1=0x18;
    TH1=0xFC;
    TF1=0;
    TR1=1;
    ET1=1;
    EA=1;
    PT1=0;
}
*/