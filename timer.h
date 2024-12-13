#ifndef timer_included
#define timer_included

extern volatile unsigned int tenths;
extern volatile unsigned char running; // Add this line

void timer_init();          // Initialize the watchdog timer
void timer_start();         // Start the timer
void timer_stop();          // Stop the timer
void timer_reset();         // Reset the timer (sets tenths to 0)

#endif // timer_included
