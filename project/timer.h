#ifndef timer_included
#define timer_included

// External variable to track tenths of a second
extern volatile unsigned int tenths;

// Function prototypes
void timer_init();          // Initialize the watchdog timer
void timer_start();         // Start the timer
void timer_stop();          // Stop the timer
void timer_reset();         // Reset the timer (sets tenths to 0)

#endif // timer_included
