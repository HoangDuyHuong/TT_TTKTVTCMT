#include "main.h"
#include "C:\Users\dellc\Downloads\TT_KTVTCMT\lib\delay.h"

// khai bao cac chan LCD
sbit RS = P2^0;
sbit E = P2^1;
#define data  P3
void lcd_cmd(unsigned char cmd){
	RS = 0;
	data = cmd; // truyen lenh
	E = 0;
	E = 1;
	delay(2);
}
void chu(char c){
	RS = 1;
	data = c; // truyen lenh
	E = 0;
	E = 1;
	delay(2);
}
void chuoi(char *str){
	unsigned char i = 0 ; // chuoi cuoi ky tu la \n nen phai cho !=0
	while(str[i]!=0){
	chu(str[i]);
	i++;
	}
}
void lcd_initial(){
	lcd_cmd(0x30);
	delay(5);
	lcd_cmd(0x30);
	delay(1);
	lcd_cmd(0x30);

	lcd_cmd(0x38);	// so dong hien thi:2	form:5x8
	lcd_cmd(0x01);	// xoa toan bo nd hien thi
	lcd_cmd(0x0C);	// bat LCD va tat con tro

}

// ham xuat ky tu ra mot vi tri chi dinh
void chu_vt(unsigned char row, unsigned char col, char c){
	unsigned char cmd;
	// di chuyen con tro den vi tr chi dinh
	cmd = (row==1?0x80:0xC0) + col - 1;
	lcd_cmd(cmd);
	// xuat chu
	chu(c);
}

// ham xuat chuoi ra mot vi tri chi dinh
void chuoi_vt(unsigned char row, unsigned char col, char *str){
	unsigned char cmd;
	// di chuyen con tro den vi tr chi dinh
	cmd = (row==1?0x80:0xC0) + col - 1;
	lcd_cmd(cmd);
	
	chuoi(str);
}

void main(){
			lcd_initial();

			chuoi_vt(2,5,"HUONG DZ");
			
//			chuoi("123456789123456789");
//			lcd_cmd(0xC0);
//			chuoi("HOANG DUY HUONG");
       while(1){
			 
      }
}