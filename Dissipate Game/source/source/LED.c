#include "LED.h"
/*
Q0-Q7->P7.0-P7.7
LED21-LED24->P5.0-P5.3
LED25-LED28->P5.4-P5.7
LED29-LED32->P6.0->P6.3
*/

void led_display_num(uint8_t number){
    switch (number){
        case 0: LED_NUM=LED_NUM_0; break;
        case 1: LED_NUM=LED_NUM_1; break;
        case 2: LED_NUM=LED_NUM_2; break;
        case 3: LED_NUM=LED_NUM_3; break;
        case 4: LED_NUM=LED_NUM_4; break;
        case 5: LED_NUM=LED_NUM_5; break;
        case 6: LED_NUM=LED_NUM_6; break;
        case 7: LED_NUM=LED_NUM_7; break;
        case 8: LED_NUM=LED_NUM_8; break;
        case 9: LED_NUM=LED_NUM_9; break;
        case 10: LED_NUM=LED_NUM_10; break;
        case 11: LED_NUM=LED_NUM_11; break;
        case 12: LED_NUM=LED_NUM_12; break;
        case 13: LED_NUM=LED_NUM_13; break;
        case 14: LED_NUM=LED_NUM_14; break;
        case 15: LED_NUM=LED_NUM_15; break;
        default: break;
    }
}

void led_select(uint8_t order){
    switch (order){
        case 1: LED_SELECT_H=0xFE; LED_SELECT_L|=0x0F; break;
        case 2: LED_SELECT_H=0xFD; LED_SELECT_L|=0x0F; break;
        case 3: LED_SELECT_H=0xFB; LED_SELECT_L|=0x0F; break;
        case 4: LED_SELECT_H=0xF7; LED_SELECT_L|=0x0F; break;
        case 5: LED_SELECT_H=0xEF; LED_SELECT_L|=0x0F; break;
        case 6: LED_SELECT_H=0xDF; LED_SELECT_L|=0x0F; break;
        case 7: LED_SELECT_H=0xBF; LED_SELECT_L|=0x0F; break;
        case 8: LED_SELECT_H=0x7F; LED_SELECT_L|=0x0F; break;
        case 9: LED_SELECT_H=0xFF; LED_SELECT_L&=0xFE; break;
        case 10: LED_SELECT_H=0xFF; LED_SELECT_L&=0xFD; break;
        case 11: LED_SELECT_H=0xFF; LED_SELECT_L&=0xFB; break;
        case 12: LED_SELECT_H=0xFF; LED_SELECT_L&=0xF7; break;
        default:break;
    }
}

void led_dispaly(void){
    uint8_t temp[4]=0;
    temp[0]=score%10;
	temp[1]=score%100/10;
	temp[2]=score%1000/100;  
	temp[3]=score/1000;
    /*upper*/
    led_select(4);
    led_display_num(temp[0]);delay(500);P7=0xFF;
    led_select(3);
    led_display_num(temp[1]);delay(500);P7=0xFF;
    led_select(2);
    led_display_num(temp[2]);P7 = P7 & ~0x80;delay(500);P7=0xFF;
    led_select(1);
    led_display_num(temp[3]);delay(500);P7=0xFF;
    temp[0]=pad%10;
	temp[1]=pad%100/10;
	temp[2]=pad%1000/100;  
	temp[3]=pad/1000;
    /*middle*/
    led_select(8);
    led_display_num(temp[0]);delay(500);P7=0xFF;
    led_select(7);
    led_display_num(temp[1]);delay(500);P7=0xFF;
    led_select(6);
    led_display_num(temp[2]);P7 = P7 & ~0x80;delay(500);P7=0xFF;
    led_select(5);
    led_display_num(temp[3]);delay(500);P7=0xFF;
}