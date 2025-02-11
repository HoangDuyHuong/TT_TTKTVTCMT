#include "main.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\lib\delay.h"

#define led P0
sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;

unsigned char code so[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void hien_thi(unsigned int num){
	unsigned char nghin, tram, chuc, dvi;
	unsigned int i;
	
	nghin = num/1000;
	tram = num%1000/100;
	chuc = num%1000%100/10;
	dvi = num%1000%100%10;
	
for(i=0; i<250; i++)
{
	led = so[nghin];
	led1 = 1;
  delay(10);
	led1 = 0;
	
	led = so[tram];
	led2 = 1;
	delay(10);
	led2 = 0;
	
	led = so[chuc];
	led3 = 1;
	delay(10);
	led3 = 0;
	
  led = so[dvi];
	led4 = 1;
	delay(10);
	led4 = 0;
}
}

void dem_nguoc_trai(unsigned char num){
	unsigned char nghin, tram;
	unsigned int i, j;
	for(j = num ;j>=0 ;j--){	
	 nghin = j / 10;
   tram = j % 10;
	for(i=0; i<100; i++){
	led = so[nghin];
	led1 = 1;
  delay(1);
	led1 = 0;
	
	led = so[tram];
	led2 = 1;
	delay(1);
	led2 = 0;
	}
	
	if(j==0){
	j=num+1;
	}
	}
}
void dem_nguoc_phai(unsigned char num){
	unsigned char chuc, dvi;
	unsigned int i, j;
	for(j = num ;j>=0 ;j--){	
	 chuc = j / 10;
   dvi = j % 10;
	for(i=0; i<100; i++){
	led = so[chuc];
	led3 = 1;
  delay(1);
	led3 = 0;
	
	led = so[dvi];
	led4 = 1;
	delay(1);
	led4 = 0;
	}
	
	if(j==0){
	j=num+1;
	}
	}
}

void main(){
P0 = 0x00;

       while(1){
//	hien_thi(2024);		 
dem_nguoc_trai(30);	
dem_nguoc_phai(25);		 
		}
}