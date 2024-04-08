#include "FSM.h"

uint8_t state=STATE0_0;

void open_device_display(void){
    WriteStr(0,0,"开心消消乐");
    WriteStr(1,0,"西交自动化");
    WriteStr(2,0,"Lanzer");
    WriteStr(3,0,"879988920@qq.com");
	delay_ms(1000);
	delay_ms(1000);
	LcdClear();	
}

void state_init(void){
    state=STATE0_0;
    WriteStr(0,0,">Dissipate Game");
    WriteStr(1,0,"XJTU ME");
    WriteStr(2,0,"README");
}

void state_transfer(void){
    if(state==STATE0_0){
        switch (P5){
        case KEY_L:{state=STATE0_2;LineClear(0);LineClear(2);}break;
        case KEY_R:{state=STATE0_1;LineClear(0);LineClear(1);}break;
        case KEY_M:{state=STATE_1;game_init();}break;
        default: break;
        }
        return;
    }
    else if(state==STATE0_1){
        switch (P5){
        case KEY_L:{state=STATE0_0;LineClear(0);LineClear(1);}break;
        case KEY_R:{state=STATE0_2;LineClear(0);LineClear(2);}break;
        case KEY_M:state=STATE_2;break;
        default: break;
        }
        return;
    }
    else if(state==STATE0_2){
        switch (P5){
        case KEY_L:{state=STATE0_1;LineClear(1);LineClear(2);}break;
        case KEY_R:{state=STATE0_0;LineClear(0);LineClear(2);}break;
        case KEY_M:state=STATE_3;break;
        default: break;
        }
        return;
    }
    else if(state==STATE_1){
        switch (P5){
        case KEY_L:press_left_key();break;
        case KEY_R:press_right_key();break;
        case KEY_M:press_middle_key();break;
        default: break;
        }
        cursor_update();
        if(pad==0){
            LcdClear();
            WriteStr(0,0,"Game Over!");
            delay_ms(1000);
            state=STATE0_0;
        }
        return;
    }
    else if(state==STATE_2){
        switch (P5){
        case KEY_L:P4&=0xFD;break;
        case KEY_M:
            LcdClear();
            WriteStr(0,0,"开心消消乐");
            WriteStr(1,0,"西交自动化");
            WriteStr(2,0,"Lanzer");
            WriteStr(3,0,"879988920@qq.com");
        break;
        case KEY_R:{LcdClear();state=STATE0_1;}break;
        default: break;
        return;
        }
    }
    else if(state==STATE_3){
        LcdClear();
        switch (P5){
        case KEY_L:
					WriteStr(0,0,"SB NT XJTU");
					WriteStr(1,0,"Fuck the Cybernetics");
					WriteStr(2,0,"of XJTU Automation");
					WriteStr(3,0,"Fuck this World");
				break;
        case KEY_M:
					WriteStr(0,0,"基于Lanzer离散状");
					WriteStr(1,0,"态转移和深度优先");
					WriteStr(2,0,"搜索和有限状态机");
					WriteStr(3,0,"祝你开心每一天");
					break;
        case KEY_R:state=STATE0_2;break;
        default: break;
        }
        return;
    }
}

void state_run(void){
    switch (state){
    case STATE0_0:
        WriteStr(0,0,">Dissipate Game");
        WriteStr(1,0,"XJTU ME");
        WriteStr(2,0,"README");
        break;
    case STATE0_1:
        WriteStr(0,0,"Dissipate Game");
        WriteStr(1,0,">XJTU ME");
        WriteStr(2,0,"README");
        break;
    case STATE0_2:
        WriteStr(0,0,"Dissipate Game");
        WriteStr(1,0,"XJTU ME");
        WriteStr(2,0,">README");
        break;
    case STATE_1:
        WriteStr(0,0,block[0]);
	    WriteStr(1,0,block[1]);
	    WriteStr(2,0,block[2]);
        break;
    case STATE_2:
        break;
    case STATE_3:
        break;
    default:
        break;
    }
}
