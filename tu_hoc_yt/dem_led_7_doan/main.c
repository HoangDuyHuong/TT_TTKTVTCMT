#include <main.h>
#include "C:\Users\dellc\Downloads\TT KIEN TRUC VA TO CHUC MAY TINH\TT KT V TCMT\lib\delay.h"

unsigned char code code7segac[]= { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };

void main(){
			unsigned char i;
       while(1){
			for(i=0; i<10;i++){
			P2 = code7segac[i];
			delay(1000);
			}
      }
}