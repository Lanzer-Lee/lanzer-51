#include "GAME.h"

uint8_t cursor=0;
uint8_t game_level4[LEVEL_LEN]={CURSOR,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,BLOCK0,0x00};
uint8_t code block_init[3][LEVEL_LEN]={
    {BLOCK0,BLOCK1,BLOCK2,BLOCK2,BLOCK1,BLOCK1,BLOCK1,BLOCK3,BLOCK4,BLOCK1,BLOCK2,BLOCK3,BLOCK4,BLOCK4,BLOCK2,BLOCK0,0x00},
    {BLOCK0,BLOCK1,BLOCK2,BLOCK2,BLOCK2,BLOCK1,BLOCK2,BLOCK4,BLOCK4,BLOCK1,BLOCK4,BLOCK4,BLOCK4,BLOCK2,BLOCK2,BLOCK0,0x00},
    {BLOCK0,BLOCK1,BLOCK1,BLOCK2,BLOCK1,BLOCK1,BLOCK1,BLOCK3,BLOCK4,BLOCK1,BLOCK2,BLOCK3,BLOCK4,BLOCK2,BLOCK2,BLOCK0,0x00}
};
uint8_t block[3][LEVEL_LEN]={0};
uint8_t pad=9;
uint8_t score=0;

void game_init(void){
    uint8_t i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<LEVEL_LEN;j++){
            block[i][j]=block_init[i][j];
        }
    }
    score=0;
    pad=9;
    set_cursor(0);
}

void set_cursor(uint8_t position){
    game_level4[position]=CURSOR;
    game_level4[cursor]=BLOCK0;
    cursor=position;
}

void cursor_update(void){
    LineClear(3);
    WriteStr(3,0,game_level4);
}

void block_update(void){
    LineClear(0);
    LineClear(1);
    LineClear(2);
    WriteStr(2,0,block[2]);
    WriteStr(1,0,block[1]);
    WriteStr(0,0,block[0]);
}

void press_right_key(void){
    if(P5==KEY_R){
        if(cursor+1==LEVEL_LEN-1) set_cursor(1);
        else set_cursor(cursor+1);
        block_down();
    }			
}

void press_left_key(void){
    if(P5==KEY_L){
        if(cursor-1<=0) set_cursor(LEVEL_LEN-2);
        else set_cursor(cursor-1);
        block_down();
    }
}

void press_middle_key(void){
    P4|=0x02;
    if(P5==KEY_M){
        block_scan();
		block_update();
        pad--;
    }
    delay_ms(200);
    P4&=0xFD;
}

void block_scan(void){
    uint8_t cursor_bolck=block[2][cursor];
    uint8_t pointer=cursor;
    if(cursor_bolck==BLOCK0){pad++;return;}
    else{
        block[2][cursor]=BLOCK0;
        while(block[2][pointer+1]==cursor_bolck){
            score++;
            pointer++;
            block[2][pointer]=BLOCK0;
        }
        pointer=cursor;
        while(block[2][pointer-1]==cursor_bolck){
            score++;
            pointer--;
            block[2][pointer]=BLOCK0;
        }
        pointer=cursor;
        if(block[1][cursor]==cursor_bolck){
            score++;
            block[1][cursor]=BLOCK0;
            while(block[1][pointer+1]==cursor_bolck){
                score++;
                pointer++;
                block[1][pointer]=BLOCK0;
            }
            pointer=cursor;
            while(block[1][pointer-1]==cursor_bolck){
                score++;
                pointer--;
                block[1][pointer]=BLOCK0;
            }
            pointer=cursor;
            if(block[0][cursor]==cursor_bolck){
                score++;
                block[0][cursor]=BLOCK0;
                while(block[1][pointer+1]==cursor_bolck){
                    score++;
                    pointer++;
                    block[1][pointer]=BLOCK0;
                }
                pointer=cursor;
                while(block[1][pointer-1]==cursor_bolck){
                    score++;
                    pointer--;
                    block[1][pointer]=BLOCK0;
                }
            }
        }
    }
}

void block_down(void){
    uint8_t pointer=0;
    for(pointer=1;pointer<LEVEL_LEN-2;pointer++){
        if(block[1][pointer]==BLOCK0){
            block[1][pointer]=block[0][pointer];
            block[0][pointer]=BLOCK0;
        }
        if(block[2][pointer]==BLOCK0){
            block[2][pointer]=block[1][pointer];
            block[1][pointer]=block[0][pointer];
            block[0][pointer]=BLOCK0;
        }
    }
}
/*
void auto_play(void){
    cursor=1;
    cursor_update();
    while(cursor<8){
        //delay_ms(500);
        block_scan();
        block_update();
        delay_ms(500);
        set_cursor(cursor+1);
        cursor_update();
    }
}
*/