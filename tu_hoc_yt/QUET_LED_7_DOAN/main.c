#include "main.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\lib\delay.h"

// khai bao ket noi
//sbit D1 = P0^0;
//sbit V1 = P0^1;
//sbit S1 = P0^2;
//sbit D2 = P0^3;
//sbit V2 = P0^4;
//sbit S2 = P0^5;

sbit led1chuc = P1^0;
sbit led1dvi = P1^1;
sbit led2chuc = P1^2;
sbit led2dvi = P1^3;

#define led1 P2
#define led2 P3

unsigned char code so[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display_number(unsigned char number) {
    unsigned char chuc = number / 10;
    unsigned char dvi = number % 10;
    unsigned int i;

    for (i = 0; i < 100; i++) { // Qu�t LED nhi?u l?n d? duy tr� d? s�ng
        // Hi?n th? h�ng ch?c
        led1 = so[chuc];
        led1chuc = 1;
        delay(1);
        led1chuc = 0;

        // Hi?n th? h�ng don v?
        led1 = so[dvi];
        led1dvi = 1;
        delay(1);
        led1dvi = 0;
    }
}

void main() {
    unsigned char dem;
    P0 = 0x00;
    dem = 30; // �?t gi� tr? ban d?u cho dem

    while (1) {
        for (dem = 30; dem <= 30; dem--) { // S?a di?u ki?n v�ng l?p d? bao g?m c? s? 0
            display_number(dem);
            delay(1000); // Tr? 1 gi�y
            if (dem == 0) {
                dem = 30; // �?t l?i gi� tr? cho dem khi d?m v? 0
            }
        }
    }
}
