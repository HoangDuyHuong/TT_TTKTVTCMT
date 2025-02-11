#include <AT89X52.H>
#include "delay/delay.h"

#define LED1    P0_0
#define LED2    P0_1
#define LED3    P0_2
#define LED4    P0_3

#define LED_PORT    P2

#define BT1        P3_1
#define SPEAK      P3_0

unsigned char index;
unsigned char led7_data[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; // Decimal to Led7seg

unsigned char key_value;
bit start = 0;
unsigned int num_product;
unsigned int num_count = 0;
unsigned char chuc_1, dv_1, chuc_2, dv_2;
unsigned char num_time = 0;
signed char time_led = 61;

#define R1    P1_0
#define Y1    P1_1
#define G1    P1_2
#define R2    P1_3
#define Y2    P1_4
#define G2    P1_5

//------------------------------------------------
void main()
{
    unsigned char j = 0;

    // Timer configuration
    TMOD = 0x11;
    TL0 = -50000 % 256;
    TH0 = -50000 / 256;
    TF0 = 1;
    TR0 = 1;
    TH1 = -5000 / 256;
    TL1 = -5000 % 256;
    TF1 = 0;
    TR1 = 1;
    EA = 1;
    ET1 = 1;
    IT1 = 1;
    ET0 = 1;

    while (1)
    {
        if (SPEAK == 0) // When P3.0 is low, switch to manual control
        {
            // Turn off all LEDs and counters
            R1 = 0; Y1 = 0; G1 = 0;
            R2 = 0; Y2 = 0; G2 = 0;
            LED1 = 0; LED2 = 0; LED3 = 0; LED4 = 0;

            // Check the state of P3.1 for LED control
            if (BT1 == 1) // When P3.1 is high
            {
                R1 = 1; G2 = 1; // Turn on R1 and G2
            }
            else // When P3.1 is low
            {
                R2 = 1; G1 = 1; // Turn on R2 and G1
            }
        }
        else
        {
            // Original LED and timer logic
            if (time_led > 33)
            {
                R1 = 1; Y1 = 0; G1 = 0;
                R2 = 0; Y2 = 0; G2 = 1;
                chuc_1 = (time_led - 31) / 10;
                dv_1 = (time_led - 31) % 10;
                chuc_2 = (time_led - 34) / 10;
                dv_2 = (time_led - 34) % 10;
            }
            else if ((time_led <= 33) && (time_led > 30))
            {
                R1 = 1; Y1 = 0; G1 = 0;
                R2 = 0; Y2 = 1; G2 = 0;
                chuc_1 = (time_led - 31) / 10;
                dv_1 = (time_led - 31) % 10;
                chuc_2 = (time_led - 31) / 10;
                dv_2 = (time_led - 31) % 10;
            }
            else if ((time_led <= 30) && (time_led >= 3))
            {
                R1 = 0; Y1 = 0; G1 = 1;
                R2 = 1; Y2 = 0; G2 = 0;
                chuc_1 = (time_led - 3) / 10;
                dv_1 = (time_led - 3) % 10;
                chuc_2 = (time_led - 0) / 10;
                dv_2 = (time_led - 0) % 10;
            }
            else if ((time_led < 3) && (time_led >= 0))
            {
                R1 = 0; Y1 = 1; G1 = 0;
                R2 = 1; Y2 = 0; G2 = 0;
                chuc_1 = (time_led) / 10;
                dv_1 = (time_led) % 10;
                chuc_2 = (time_led) / 10;
                dv_2 = (time_led) % 10;
            }
        }
    }
}
/* Timer 0 interrupt service routine */
void T0_ISR(void) interrupt 1
{
    TR0 = 0;
    TF0 = 0;
    TL0 = -50000 % 256;
    TH0 = -50000 / 256;

    num_time++;
    if (num_time == 20)
    {
        num_time = 0;
        time_led--;
        if (time_led < 0)
            time_led = 61;
    }

    TR0 = 1;
}

/* Timer 1 interrupt service routine */
void T1_ISR(void) interrupt 3 // Using Timer 1 to scan LEDs
{
    TR1 = 0;
    TF1 = 0;
    TH1 = -5000 / 256; // Reload Timer 1
    TL1 = -5000 % 256;
    index++;
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;

    if (index == 1)
    {
        LED1 = 1;
        LED_PORT = led7_data[chuc_1];
    }
    else if (index == 2)
    {
        LED2 = 1;
        LED_PORT = led7_data[dv_1];
    }
    else if (index == 3)
    {
        LED3 = 1;
        LED_PORT = led7_data[chuc_2];
    }
    else if (index == 4)
    {
        LED4 = 1;
        LED_PORT = led7_data[dv_2];
        index = 0;
    }

    TR1 = 1;
}

/* External interrupt 1 service routine */
void IT1_ISR(void) interrupt 2
{
    num_count++;
}