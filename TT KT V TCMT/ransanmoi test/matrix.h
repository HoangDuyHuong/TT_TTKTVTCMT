#ifndef MATRIX_H
#define MATRIX_H

#include <REG51.h>
#include <intrins.h>

sbit SRCLK = P3^6; // Shift Register Clock Pin
sbit RCLK = P3^5;  // Register Clock Pin
sbit SER = P3^4;   // Serial Data Input

unsigned char code TAB[8]  = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 121; j++);
}

void Hc595SendByte(unsigned char dat) {
    unsigned char a;
    SRCLK = 0;
    RCLK = 0;
    for(a = 0; a < 8; a++) {
        SER = (dat & 0x80) >> 7;
        dat <<= 1;
        SRCLK = 1;
        _nop_();
        _nop_();
        SRCLK = 0;
    }
    RCLK = 1;
    _nop_();
    _nop_();
    RCLK = 0;
}

void display_matrix(unsigned char matrix[8]) {
    unsigned char i;
    for(i = 0; i < 8; i++) {
        Hc595SendByte(TAB[i]);
        Hc595SendByte(matrix[i]);
        delay(100);
    }
}

#endif
