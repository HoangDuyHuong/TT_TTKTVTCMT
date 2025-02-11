#include"main.h"
#include"..\lib\LCD4.h"

void main()
{
	Lcd_Init();

	Lcd_Chr(1,2,'A');
	Lcd_Chr_Cp('B');
	
	Lcd_Out(2,1,"Hello World");

	Lcd_Cmd(_LCD_CLEAR);

	Lcd_Out_Cp("123");
	while(1)
	{

	}
}