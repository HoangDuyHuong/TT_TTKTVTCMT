#include "matrix.h"
#include <INTRINS.h>
#include <REG51.h>
#define COMMONPORTS		P0

// Define button pins
sbit UP = P3^2;  // Button for UP
sbit DOWN = P3^3;  // Button for DOWN
sbit LEFT = P3^1;  // Button for LEFT
sbit RIGHT = P3^0; // Button for RIGHT

unsigned char snake[64];
unsigned char food;
unsigned char direction = 0; // 0: Up, 1: Down, 2: Left, 3: Right
unsigned char snake_length = 1;
unsigned char display_buffer[8];

void init_game() {
    unsigned char i;
    for (i = 0; i < 64; i++) {
        snake[i] = 0;
    }
    snake[0] = 0; // Start position
    food = 10;     // Initial food position
}

void update_snake() {
    unsigned char i;
    for (i = snake_length; i > 0; i--) {
        snake[i] = snake[i-1];
    }
    if (direction == 0) snake[0] = (snake[0] - 8 + 64) % 64; // Up
    else if (direction == 1) snake[0] = (snake[0] + 8) % 64; // Down
    else if (direction == 2) snake[0] = (snake[0] - 1 + 64) % 64; // Left
    else if (direction == 3) snake[0] = (snake[0] + 1) % 64; // Right
}

void check_collision() {
    unsigned char i;
    for (i = 1; i < snake_length; i++) {
        if (snake[0] == snake[i]) {
						snake_length = 1; 
						snake[0] = 0; // Reset to initial position food = (food + 17) % 64; // Reposition food
            init_game();
        }
    }
    if (snake[0] == food) {
        snake_length++;
        food = (food + 17) % 64;
    }
}

void update_display_buffer() {
    unsigned char i, row, col;
    for (i = 0; i < 8; i++) {
        display_buffer[i] = 0x00;
    }
    for (i = 0; i < snake_length; i++) {
        row = snake[i] / 8;
        col = snake[i] % 8;
        display_buffer[row] |= (1 << col);
    }
    row = food / 8;
    col = food % 8;
    display_buffer[row] |= (1 << col);
}

void main() {
    unsigned char tab, j;
    unsigned int i;

    init_game();
    while(1) {
        if (UP == 0) direction = 0;
        if (DOWN == 0) direction = 1;
        if (LEFT == 0) direction = 2;
        if (RIGHT == 0) direction = 3;
        
        update_snake();
        check_collision();
        update_display_buffer();

        for(i = 0; i < 50; i++) { // Refresh the display
            for(tab = 0; tab < 8; tab++) {
                Hc595SendByte(0x00);
                COMMONPORTS = TAB[tab];
                Hc595SendByte(display_buffer[tab]);
                delay(2);
            }
        }

        delay(1); // Adjust speed
    }
}
