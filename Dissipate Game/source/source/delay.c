#include "delay.h"

void delay_ms(uint16_t time){
    uint16_t i,j;
    for(i=0;i<time;i++){
        for(j=0;j<1300;j++);
    }
}

void delay(uint16_t k){
    do{} while(--k);
}
/*
void delay_us(uint16_t times){
	uint16_t i,j;
	for (i = 0; i< times; i++){
		for (j = 0; j < 11; j++){
			_nop_();
    	}
 	}
}
*/