#ifndef switches_included
#define switches_included

// Switch Module
// Provides definitions and functions for handling button inputs on P2.0 and P2.1.

// Switch bit definitions
#define SW1 BIT0  // Switch 1 (connected to P2.0)
#define SW2 BIT1  // Switch 2 (connected to P2.1)

// Mask for all switches
#define SWITCHES (SW1 | SW2)

// External variable to track switch state
extern char switch_state_down;

// Function prototypes
void switch_init();                  // Initialize the switches
void switch_interrupt_handler();     // Handle switch interrupts

#endif // switches_included