#include <msp430.h>
#include "buttons.h"

void configureButtons() {
    P1DIR &= ~(BIT3 + BIT4); // Set P1.3 and P1.4 as inputs
    P1REN |= (BIT3 + BIT4);  // Enable pull-up/down resistors
    P1OUT |= (BIT3 + BIT4);  // Set pull-up resistors
    P1IE |= (BIT3 + BIT4);   // Enable interrupts for buttons
    P1IES |= (BIT3 + BIT4);  // Trigger on high-to-low transition
    P1IFG &= ~(BIT3 + BIT4); // Clear interrupt flags
}

void __interrupt_vec(PORT1_VECTOR) Port_1() {
    if (P1IFG & BIT3) { // Button on P1.3 (e.g., Start/Stop)
        toggleStopwatchState(); // Implement in main or another module
        P1IFG &= ~BIT3;         // Clear flag
    }
    if (P1IFG & BIT4) { // Button on P1.4 (e.g., Reset)
        resetStopwatch(); // Implement in main or another module
        P1IFG &= ~BIT4;   // Clear flag
    }
}
