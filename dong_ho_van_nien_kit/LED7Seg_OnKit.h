//---------- Include -----------
#ifndef _LED7SEG_ONKIT_H_
#define _LED7SEG_ONKIT_H_
// Thư viện cơ sở cho AT89C52
#include <REGX52.h>
#include "base_lib.h"
#include "ThreeWiresProtocol.h"

//---------- Macros -----------


//Định nghĩa lại kiểu dữ liệu
//typedef unsigned int  uint;

//Các chân chọn vị trí LED.
sbit GND0 = P2^2;
sbit GND1 = P2^3;
sbit GND2 = P2^4;

//Chân điều khiển từng LED trong LED7seg
#define LED_7SEG P0

const ubyte DIGIT_CODE[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
                           0X7D, 0X07, 0X7F, 0X6F, 0X0, 0X1, 0x40, 0x8};

ubyte LED[8] = {0, 0, 0, 0, 0, 0, 0, 0};
ubyte DISP_Time = 5;//mili-sec
ubyte DISP_Freq = 24;//Hz
ubyte DISP   = 0; //Control of disp;


void set_disp_freq(uint newDISP_Freq){
    DISP_Freq = newDISP_Freq;
    DISP_Time = 1000/(DISP_Freq*8);
}

/*
  8   7   6   5   4   3   2   1  
  _   _   _   _   _   _   _   _  
 |_| |_| |_| |_| |_| |_| |_| |_|
 |_|.|_|.|_|.|_|.|_|.|_|.|_|.|_|.
Hàm này sẽ chọn LED ở vị trí POS, mã hiển thị là CODE.
VD: Hiển thị số "1", CODE = 0x06
*/
void led7seg_disp(uint  POS, uint  CODE){
    switch (POS) {
        case 0x1:
            { GND0 = 0; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x2:
            { GND0 = 1; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x3:
            { GND0 = 0; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x4:
            { GND0 = 1; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x5:
            { GND0 = 0; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x6:
            { GND0 = 1; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x7:
            { GND0 = 0; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x8:
            { GND0 = 1; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
        default:
            LED_7SEG = 0x0;
    }
}


/*
Hiển thị trong một GIÂY cả 8 LED7Seg.
Nội dung hiển thị của LED thứ i tuỳ thuộc vào 
giá trị chứa trong LED[i].
*/
void Disp8leds7seg(){
    uint i = 0; 
    uint j = 0;
    for(i =0; i < 8; ++i){
        led7seg_disp(i+1, LED[i]);
        for(j = 0; j < 150; ++j);
    }
    LED_7SEG = 0x0;
}

#endif