#include <reg51.h>
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\lib\delay.h"
sbit LED1 = P2^0; 
sbit LED2 = P2^1; 
sbit LED3 = P2^2;
sbit LED4 = P2^3; 

unsigned char code seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; 

void display(unsigned int left, unsigned int right) {
    unsigned char i, digit1, digit2, digit3, digit4;

    digit1 = right % 10;
    right = right / 10;
    digit2 = right % 10;
    digit3 = left % 10;
    left = left / 10;
    digit4 = left % 10;

for(i=0; i=50; i++){
    P0 = seg[digit4];
    LED1 = 0;
    delay(1);
    LED1 = 1;


    P0 = seg[digit3];
    LED2 = 0;
    delay(1);
    LED2 = 1;

    P0 = seg[digit2];
    LED3 = 0;
    delay(1);
    LED3 = 1;

    P0 = seg[digit1];
    LED4 = 0;
    delay(1);
    LED4 = 1;
	}	
}

void main() {
    unsigned int left_count = 30;
    unsigned int right_count = 10;

    while (1) {
        display(left_count, right_count);

        if (right_count == 0) {
            right_count = 10;
            if (left_count > 0) {
                left_count--;
            }
        } else {
            right_count--;
        }
delay(100);
    }
}
