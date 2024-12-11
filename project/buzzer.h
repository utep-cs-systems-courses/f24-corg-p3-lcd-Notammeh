#ifndef buzzer_included
#define buzzer_included

// Frequencies for common tones (in clock cycles)
#define C6 1108  // C note, 6th octave
#define D6 1174  // D note, 6th octave
#define E6 1318  // E note, 6th octave
#define G6 1567  // G note, 6th octave

// Function declarations

/**
 * Initialize the buzzer hardware.
 * Configures the Timer and P2.6 pin for PWM output.
 */
void buzzer_init();

/**
 * Set the buzzer frequency.
 * @param cycles: Clock cycles for the desired frequency.
 *                (e.g., 1108 for C6, 1318 for E6, etc.)
 */
void buzzer_set_period(short cycles);

/**
 * Play a beep sound for start/stop events.
 */
void buzzer_beep_event();

/**
 * Play a distinct sound for the reset event.
 */
void buzzer_beep_reset();

/**
 * Play a periodic beep (e.g., every 5 seconds).
 */
void buzzer_periodic_beep();

#endif // buzzer_included
