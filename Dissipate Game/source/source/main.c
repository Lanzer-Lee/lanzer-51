#include <stdio.h>
#include "sys.h"
#include "c8051f020.h"
#include "lcd.h"
#include "BUZZER.h"
#include "TIMER.h"
#include "LED.h"
#include "delay.h"
#include "GAME.h"
#include "FSM.h"
#include "KEY.h"

sbit INT1 = P0^2; //P0.3

void Port_IO_Init()
{
	//set P4[1] to push_pull model
    P74OUT |= 0x01;

    //close the alam P4.1
    P4 &= 0xfd;
	
	//uart1,int1
	XBR1 |= 0x10;//XBR1 |= 0x14
	XBR2 |= 0x44;
}

void Oscillator_Init()
{
    int i = 0;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    OSCICN    = 0x08;
}


void Interrupt_Init()
{
	//INT1
	//low level triggle
	IT1 = 0;
	//enable INT1
	EX1 = 1;
	//enable all interrupt
	EA = 1;
}

void Init_Device(void)
{
    //disable watchdog
    EA = 0;
    WDTCN = 0xde;
    WDTCN = 0xad;
    EA = 1;
    Oscillator_Init();
    Port_IO_Init();
	Timer0_Init();
	//TIM1_Init();
	Interrupt_Init();
    LcdInit();
}

void main(void)
{	
	Init_Device();
	INT1 = 1;
	open_device_display();
	state_init();
    while(1){	
		led_dispaly();	
    }
}

void INT1_ISR(void) interrupt 2
{
	state_transfer();
	state_run();
}

void Timer1_Routine() interrupt 3
{
	/*
	if(FreqTable[FreqSelect]){
		TL1 = FreqTable[FreqSelect]%256;		
		TH1 = FreqTable[FreqSelect]/256;		
		buzzer_high();
		buzzer_low();
	}
	*/
}






