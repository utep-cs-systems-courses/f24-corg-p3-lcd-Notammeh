#include <msp430.h>
#include "timer.h"
#include "lcd_states.h"

volatile unsigned int tenths = 0;
volatile unsigned char running = 0;

void timer_init() {
    WDTCTL = WDTPW | WDTHOLD;
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDT_MDLY_32;
    IE1 |= WDTIE;
}

void timer_start() {
    running = 1;
}

void timer_stop() {
    running = 0;
}

void timer_reset() {
    running = 0;
    tenths = 0;
    lcd_update_time(tenths);
}
