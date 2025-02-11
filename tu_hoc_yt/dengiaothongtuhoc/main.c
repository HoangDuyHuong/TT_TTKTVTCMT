#include"main.h"
#include"C:\Users\dellc\Downloads\TT_KTVTCMT\lib\delay.h"

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

unsigned char code so[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92,0x82, 0xF8, 0x80, 0x90};

//void ct_dem_lui_led1(unsigned char count){
//		unsigned char dem, chuc, dvi;
//		unsigned int i;
//		dem  = count;
//			for(dem = count; dem>=0; dem--){
//			chuc = dem/10;
//			dvi = dem%10;
//			if(dem == 0){
//			dem = count + 1;
//			}
//			for(i=0; i<5; i++){
//				led1 = so[chuc];
//				led1chuc = 1;
//				delay(50);
//				led1chuc = 0;
//				
//				// dvi
//				led1 = so[dvi];
//				led1dvi = 1;
//				delay(50);
//				led1dvi = 0;	
//				
//			}
//			
//			}
//}

//void ct_dem_lui_led2(unsigned char count){
//		unsigned char dem, chuc, dvi;
//		unsigned int i;
//		dem  = count;
//			for(dem = count; dem>=0; dem--){
//			chuc = dem/10;
//			dvi = dem%10;
//			if(dem == 0){
//			dem = count + 1;
//			}
//			for(i=0; i<5; i++){
//				led2 = so[chuc];
//				led2chuc = 1;
//				delay(50);
//				led2chuc = 0;
//				
//				// dvi
//				led2 = so[dvi];
//				led2dvi = 1;
//				delay(50);
//				led2dvi = 0;	
//				
//			}
//			
//			}
//}




void main(){
// lap trinh den giao thong: Do 30s, vang:5s, xanh:25s

	
       while(1){
//ct_dem_lui_led1(30);
//ct_dem_lui_led2(20);


		unsigned char dem, chuc, dvi;
		unsigned int i;
		dem  = 30;
		
			for(dem = 30; dem>=0; dem--){
			chuc = dem/10;
			dvi = dem%10;
			if(dem == 0){
			dem = 30 + 1;
			}
			for(i=0; i<5; i++){
				led1 = so[chuc];
				led1chuc = 1;
				delay(50);
				led1chuc = 0;
				
				// dvi
				led1 = so[dvi];
				led1dvi = 1;
				delay(50);
				led1dvi = 0;	
				
			}
			
			}
			
      }
}