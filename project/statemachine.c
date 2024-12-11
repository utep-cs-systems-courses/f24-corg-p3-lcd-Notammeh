#include "lcd_states.h"
#include "timer.h"
#include "led.h"

int state = STOPPED; // Initialize to STOPPED state

// Advances to the next state
void state_advance() {
    switch (state) {
    case STOPPED:
        state = RUNNING; // Move to RUNNING state
        break;

    case RUNNING:
        state = RESET; // Move to RESET state
        break;

    case RESET:
        state = STOPPED; // Move to STOPPED state
        break;

    default:
        state = STOPPED; // Default to STOPPED state
        break;
    }
}

// Updates actions based on the current state
void state_update() {
    static int prevState = -1; // Track previous state for screen updates

    if (state != prevState) { // Only update screen when state changes
        prevState = state;

        switch (state) {
        case STOPPED:
            // Turn off LED, stop timer, and clear screen
            led_off();
            timer_stop();
            clearScreen(COLOR_BLUE);
            drawString5x7(20, 20, "STOPPED", COLOR_WHITE, COLOR_BLUE);
            break;

        case RUNNING:
            // Turn on LED, start timer, and display dual ball animation
            led_on();
            timer_start();
            lcd_animation_dual_balls(); // Show dual ball animation
            break;

        case RESET:
            // Turn off LED, reset timer, and clear screen with "RESET" label
            led_off();
            timer_reset();
            clearScreen(COLOR_BLUE);
            drawString5x7(20, 20, "RESET", COLOR_WHITE, COLOR_BLUE);
            break;

        default:
            state = STOPPED; // Default to STOPPED state for invalid inputs
            break;
        }
    }
}
