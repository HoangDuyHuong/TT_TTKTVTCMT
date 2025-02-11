#include "main1.h"
#include "C:\Users\dellc\Downloads\TT KIEN TRUC VA TO CHUC MAY TINH\TT KT V TCMT\lib\delay.h"
unsigned char code code7segac[]= { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };

// khai bao ket noi
sbit dendo = P0^0;
sbit denvang = P0^1;
sbit denxanh = P0^2;
#define ledchuc  P2
#define leddvi  P3


void main(){
	unsigned char i;
       while(1){
			// den do
			dendo = 1;
			denvang = 0;
			denxanh = 0;
			for(i=20; i>=0; i--)
			{
			ledchuc = code7segac[i/10];
			leddvi = code7segac[i%10];
			delay(1000);
			}
			// den vang
			dendo = 0;
			denvang = 1;
			denxanh = 0;
			for(i=5; i>=0; i--)
			{
			ledchuc = code7segac[i/10];
			leddvi = code7segac[i%10];
			delay(1000);
			}
			// den xanh
			dendo = 0;
			denvang = 0;
			denxanh = 1;
			for(i=25; i>=0; i--)
			{
			ledchuc = code7segac[i/10];
			leddvi = code7segac[i%10];
			delay(1000);  
			}
			
				
      }
}