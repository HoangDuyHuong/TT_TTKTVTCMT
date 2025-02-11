#include "main.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\tu_hoc_yt\giao_tiep_lcd_4_bit\Bai018\Bai018\Lib\LCD4.h"


void main(){

	Lcd_Init();
	Lcd_Chr(1,4,'H');
	Lcd_Chr_Cp('i');
	Lcd_Cmd(_LCD_CLEAR);
	Lcd_Out(2,4,"HUONG");
	Lcd_Out_Cp("HOANG");
       while(1){

      }
}