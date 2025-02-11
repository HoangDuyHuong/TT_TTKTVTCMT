#include <REGX52.H>  

unsigned char irKey = 0;
unsigned long bitPattern = 0;
unsigned long newKey = 0;
unsigned long pre_newKey = 0;
unsigned char timerValue;
unsigned char msCount = 0;
char pulseCount = 0;
void Timer0_Init(void);
unsigned char Decode_IRKey(unsigned char key);
void ToggleLED(unsigned char ledNum);  
unsigned char tat1,tat2,tat3;
void main(){
    P2 = 0xFF;         
    Timer0_Init();     
    EA = 1;            
    while (1)
    {
			irKey=Decode_IRKey(newKey);
			if(irKey==1)
				P2_0=0;
			if(irKey==2)
				P2_1=0;
			if(irKey==3)
				P2_2=0;
			if(irKey==4)
				P2_0=1;
			if(irKey==5)
				P2_1=1;
			if(irKey==6)
				P2_2=1;
			if(P3_2==0)
				P2_4=0;
			if(P3_1==0)
				P2_4=1;
		}    
}

unsigned char Decode_IRKey(unsigned char key){
    unsigned char returnValue = 0;
    switch (key)
    {
    case 0xFF30CF:  // Phím '1'
        returnValue = 1;
        break;
    case 0xFF18E7:  // Phím '2'
        returnValue = 2;
        break;
    case 0xFF7A85:  // Phím '3'
        returnValue = 3;
        break;
		  case 0xFF10EF:  // Phím '4' 
        returnValue = 4;
        break;
    case 0xFF38C7:  // Phím '5' 
        returnValue = 5;
        break;
    case 0xFF5AA5:  // Phím '6' 
        returnValue = 6;
        break;
    case 0xFF42BD:  // Phím '7' 
        returnValue = 7;
        break;
    case 0xFF4AB5:  // Phím '8' 
        returnValue = 8;
        break;
    case 0xFF52AD:  // Phím '9' 
        returnValue = 9;
        break;
    default:
        returnValue = 0;  // Mã không h?p l?
        break;
    }
		
    return returnValue;
}

// Ng?t Timer0 d? d?m mili giây
void timer0_isr() interrupt 1
{
    if (msCount < 50)
        msCount++;
    
    // C?u hình l?i giá tr? Timer0 d? ti?p t?c d?m 1ms
    TH0 = 0xFC; 
    TL0 = 0x18;  // Giá tr? du?c tính cho t?n s? 12MHz
}

// Ng?t ngoài d? nh?n tín hi?u IR
void externalIntr0_ISR() interrupt 0
{
    timerValue = msCount;
    msCount = 0;
    
    TH0 = 0xFC; 
    TL0 = 0x18;  // C?u hình l?i Timer0

    pulseCount++;
    
    if ((timerValue >= 50))  // N?u d? r?ng xung l?n hon 50ms, dánh d?u b?t d?u khung (Start Of Frame)
    {
        pulseCount = -2;     // B? qua 2 xung d?u
        bitPattern = 0;
    }
    else if ((pulseCount >= 0) && (pulseCount < 32)) // Tích luy giá tr? bit t? 0 d?n 31
    {
        if (timerValue >= 2) // Xung có d? r?ng > 2ms là bit 1
            bitPattern |= (unsigned long)1 << (31 - pulseCount);
    }
    else if (pulseCount >= 32) // K?t thúc khung khi nh?n d? 32 bit
    {
        newKey = bitPattern;  // Luu mã phím m?i
        pulseCount = 0;
    }
}

// Kh?i t?o Timer0
void Timer0_Init(){
    TMOD |= 0x01;     // C?u hình Timer0 ? ch? d? 16-bit (MODE 1)
    TH0 = 0xFC; 
    TL0 = 0x18;       // Giá tr? kh?i t?o cho 1ms t?i t?n s? 12 MHz
    TR0 = 1;          // B?t d?u Timer0
    ET0 = 1;          // Cho phép ng?t Timer0
    IT0 = 1;          // C?u hình ng?t ngoài INT0 kích ho?t ? c?nh xu?ng
    EX0 = 1;          // Cho phép ng?t ngoài INT0
}

// Hàm d?i tr?ng thái LED tuong ?ng
void ToggleLED(unsigned char ledNum){
    // ledNum = 1, 2, 3 tuong ?ng v?i LED t?i P2.0, P2.1, P2.2
    switch (ledNum) {
        case 1: 
            P2 ^= 0x01;  // Ð?i tr?ng thái LED1 (P2.0)
            break;
        case 2: 
            P2 ^= 0x02;  // Ð?i tr?ng thái LED2 (P2.1)
            break;
        case 3: 
            P2 ^= 0x04;  // Ð?i tr?ng thái LED3 (P2.
		}
	}