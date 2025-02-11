
#ifndef _CALENDAR_ONKIT_H_
#define  _CALENDAR_ONKIT_H_

#include "base_lib.h"
#include "DS1302.h"
#include "LED7Seg_OnKit.h"
#include "ThreeWiresProtocol.h"

#define A_DIGIT 0x77
#define P_DIGIT 0x73

#define VIEW_DATE 0x0
#define VIEW_TIME 0x1
#define SETTING_DATE 0x2
#define SETTING_TIME 0x3

sbit TRIGGER0 = P3^2;
sbit TRIGGER1 = P3^3;

ubyte MODE = VIEW_TIME;
ubyte EDIT_POS = 1;
ubyte F_EXIT = 0;

TIME time;

void HHMMSS_disp(){
  ds1302_read_time(&time, 0x7);
  LED[7] = DIGIT_CODE[(time.HOUR/10)%10];
  LED[6] = DIGIT_CODE[time.HOUR%10];
  LED[5] = 0x40;
  LED[4] = DIGIT_CODE[(time.MINUTE/10)%10];
  LED[3] = DIGIT_CODE[time.MINUTE%10];
  LED[2] = 0x40;
  LED[1] = DIGIT_CODE[(time.SECOND/10)%10];
  LED[0] = DIGIT_CODE[(time.SECOND)%10];
  DISP = 1;
  Disp8leds7seg();
}

void YYMMDD_disp(){
  ds1302_read_time(&time, 0x38);
  LED[7] = DIGIT_CODE[(time.YEAR/10)%10];
  LED[6] = DIGIT_CODE[time.YEAR%10];
  LED[5] = 0x40;
  LED[4] = DIGIT_CODE[(time.MONTH/10)%10];
  LED[3] = DIGIT_CODE[time.MONTH%10];
  LED[2] = 0x40;
  LED[1] = DIGIT_CODE[(time.DATE/10)%10];
  LED[0] = DIGIT_CODE[(time.DATE)%10];
  DISP = 1;
  Disp8leds7seg();
}

void calendar_disp(){
  switch (MODE) {
    case VIEW_TIME:
      HHMMSS_disp();
      break;
    case VIEW_DATE:
      YYMMDD_disp();
      break;
  }
}

void calendar_initial(){
  EA = 1; EX0 = 1; IT0 = 1;
  ds1302_initial();
  time.SECOND = 0;
  time.MINUTE = 01;
  time.HOUR = 11;
  time.DAY = TUE;
  time.DATE = 1;
  time.MONTH = 10;
  time.YEAR  = 24;
  ds1302_write_time(&time,0x7F);
  set_disp_freq(48);
}

static void Interrupt_Action(void) interrupt 0 {
  MODE=(MODE+1)%2;
  DISP = 0;
}

#endif