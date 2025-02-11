#include <REGX51.H>

int sangdan[9] = {0X00, 0X01, 0X03, 0X07, 0X0F, 0X1F, 0X3F, 0X7F, 0XFF};
int tatdan[9] =  {0XFF, 0XFE, 0XFC, 0XF8, 0XF0, 0XE0, 0XC0, 0X80, 0X00};

void delay(long time)
{
	time = time * 25;
	while(time--) {;}
}

int i;

void main()
{
	P1=0X00;
	while(1)
	{
		
		for(i=0; i<8; i++)
		{
			P1 = sangdan[i];
			delay(250);
		}
		for(i=8; i>0; i--)
		{
			P1 = tatdan[8-i];
			delay(250);
		}
	}
}