#include <msp430.h>
#include "lcd_states.h"     // LCD display management
#include "buzzer.h"         // Buzzer control
#include "led.h"            // LED control (with assembly toggle)
#include "switches.h"       // Button handling
#include "statemachine.h"   // State machine for stopwatch logic
#include "timer.h"          // Timer for stopwatch functionality

// Main function
void main() {
    // Initialization
    configureClocks();       // Configure system clocks
    lcd_init();              // Initialize LCD display
    buzzer_init();           // Initialize the buzzer
    led_init();              // Initialize the LED
    switch_init();           // Initialize switches (buttons)
    timer_init();            // Initialize the timer
    enableWDTInterrupts();   // Enable Watchdog Timer interrupts
    clearScreen(COLOR_BLUE); // Clear the LCD screen to blue

    // Main loop
    while (1) {
        // Update state-specific actions
        state_update();

        // Delay to avoid excessive CPU usage
        __delay_cycles(50000);
    }
}

// Watchdog Timer Interrupt Handler
void __interrupt_vec(WDT_VECTOR) WDT() {
    static unsigned int tickCount = 0;

    // If the stopwatch is running, increment time
    if (running) {
        tickCount++;
        if (tickCount >= 25) {   // ~10 ticks/sec = ~1/10th of a second
            tenths++;
            tickCount = 0;

            // Update the LCD with the new time
            lcd_update_time(tenths);

            // Play a periodic beep every 5 seconds
            if (tenths % 50 == 0) {
                buzzer_periodic_beep();
            }
        }
    }
}

// Port 2 Interrupt Handler for Button Presses
void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {         // Check if a button caused the interrupt
        P2IFG &= ~SWITCHES;         // Clear pending interrupts
        switch_interrupt_handler(); // Handle button press
    }
}

