#include <REGX51.H>
// khai bao ket noi chan
sbit dexanh = P0^0;
sbit devang = P0^1;
sbit dendo = P0^2;
sbit dexanh = P0^3;
sbit devang = P0^4;
sbit dedo = P0^5;
void delay(long time){
	
	time = time * 25;
	while(time--) {;}
}
char so [] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
void main(){
int i;
	// bat den do
	deno = 0;
	denxanh = 1;
	denvang = 1;
	for(i=20; i>=0; i--) {
		P1^1 = 1 ;
		P2 = so[j%10];
		P1^2 = 0;
		delay(3000);
		P1^1 = 1 ;
		P2 = so[j/10];
		P1^2 = 0;
		delay(3000);
		
	}
}