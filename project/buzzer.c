#include <msp430.h>
#include "buzzer.h"

// Initialize the buzzer
void buzzer_init() {
    P2DIR |= BIT6;       // Set P2.6 as output (buzzer pin)
    P2SEL |= BIT6;       // Connect Timer output to P2.6
    TA0CCR0 = 0;         // Initialize Timer A0
    TA0CCTL1 = OUTMOD_7; // Reset/Set mode
    TA0CCR1 = 0;         // No output yet
    TA0CTL = TASSEL_2 + MC_1; // SMCLK, Up mode
}

// Set the buzzer frequency
void buzzer_set_period(short cycles) {
    TA0CCR0 = cycles;      // Set timer period
    TA0CCR1 = cycles >> 1; // 50% duty cycle
}

// Play a simple melody (C6, E6, G6)
void musica() {
    // Melody definition (C6, E6, G6), 0 ends the sequence
    static const short melody[] = {C6, E6, G6, 0};
    static int note_index = 0;

    if (melody[note_index]) {
        buzzer_set_period(melody[note_index]); // Play the current note
        note_index++;
    } else {
        buzzer_set_period(0); // Stop the buzzer
        note_index = 0;       // Reset the melody
    }
}

// Update melody periodically
void musica_update() {
    musica(); // Call melody playback
}