#include "main.h"
#include "C:\Users\dellc\Downloads\TT KIEN TRUC VA TO CHUC MAY TINH\TT KT V TCMT\lib\delay.h"
#define led P2

void sangtatled(){
		unsigned char i;
		led = 0x00;
		for(i=0; i<8; i++){
			led = (led<<1) | 0x01;
			delay(200);
			}
		for(i=0; i<8; i++){
			led = (led<<1);
			delay(200);
		}

}
void sang_xen_ke(){
		unsigned char i;
		for(i=0; i<10; i++){
		led = 0x55;
			delay(200);
		led = 0xAA;
			delay(200);
		}

}
void main(){
	while(1){
		sangtatled();
		sang_xen_ke();
	}
}



