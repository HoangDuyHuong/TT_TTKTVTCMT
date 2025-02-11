#ifndef _BASE_LIB_H_
#define _BASE_LIB_H_

#ifndef elif
#define elif else if
#endif
#ifndef DECREASE_ONE
#define DECREASE_ONE(VAR) VAR = (VAR>0?(VAR-1):VAR)
#endif
#ifndef FOR
#define FOR(i, a, b) for(i = (a); i <= (b); ++i)
#endif
#ifndef FOR_reverse
#define FOR_reverse(i, a, b) for(i = (a); i >= (b); --i)
#endif

typedef unsigned char ubyte;
typedef unsigned int uint ;

static void delay_us(uint t){
    uint i = 0; 
    for(i = 0; i < t; i = i + 1){
        // do nothin'
    }
}

static void delay_ms(uint t){
    uint i = 0; 
    for(i = 0; i < t*1200; i = i + 1){
        // do nothin'
    }
}

enum enum_STATE{ LOW  = 0, HIGH = 1 };



#endif