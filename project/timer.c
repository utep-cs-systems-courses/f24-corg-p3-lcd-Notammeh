#include <msp430.h>
#include "timer.h"
#include "lcd_states.h" // To update time on the display

volatile unsigned int tenths = 0;  // Track tenths of a second
volatile unsigned char running = 0; // Stopwatch running state

// Initialize the watchdog timer
void timer_init() {
    WDTCTL = WDTPW | WDTHOLD; // Stop the watchdog timer initially
    // Configure WDT to trigger an interrupt every ~1/10th of a second
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDT_MDLY_32;
    IE1 |= WDTIE;             // Enable WDT interrupt
}

// Start the timer
void timer_start() {
    running = 1;              // Set running state to true
}

// Stop the timer
void timer_stop() {
    running = 0;              // Set running state to false
}

// Reset the timer
void timer_reset() {
    running = 0;              // Stop the timer
    tenths = 0;               // Reset tenths to 0
    lcd_update_time(tenths);  // Immediately update the display
}

// Watchdog Timer Interrupt Handler
void __interrupt_vec(WDT_VECTOR) WDT() {
    static unsigned int count = 0;

    if (running) {            // If the stopwatch is running
        count++;
        if (count >= 25) {    // ~10 ticks/sec -> ~1/10th of a second
            tenths++;
            count = 0;        // Reset count
            lcd_update_time(tenths); // Update LCD with the new time
        }
    }
}

