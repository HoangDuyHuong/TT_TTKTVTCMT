#include "main.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\tu_hoc_yt\dong_ho_real_time_th\Bai019 (1)\Bai019\Lib\Lcd4.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\tu_hoc_yt\dong_ho_real_time_th\Bai019 (1)\Bai019\Lib\Rtc_Ds1307.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\tu_hoc_yt\dong_ho_real_time_th\Bai019 (1)\Bai019\Lib\Soft_I2C.h"
void main(){
		unsigned char hour, minute, second, mode, day, date, month, year, old_second;
		Soft_I2c_Init();
		Ds1307_Init();
		Lcd_Init();
		
		
    while(1){
		Ds1307_Read_Time(&hour, &minute, &second, &mode);
		if(old_second!=second){
		old_second=second;
		Lcd_Chr(1,5,hour/10+0x30);
		Lcd_Chr_Cp(hour%10+0x30);
		Lcd_Chr_Cp(':');
		
		Lcd_Chr_Cp(minute/10+0x30);
		Lcd_Chr_Cp(minute%10+0x30);
		Lcd_Chr_Cp(':');
		Lcd_Chr_Cp(second/10+0x30);
		Lcd_Chr_Cp(second%10+0x30);
		
		}
      }
}