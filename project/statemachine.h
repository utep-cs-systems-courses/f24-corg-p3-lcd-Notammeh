#ifndef statemachine_included
#define statemachine_included

// State definitions
#define STOPPED 0
#define RUNNING 1
#define RESET 2

// Global state variable
extern int state;

// Function prototypes
void state_advance();        // Advances to the next state
void state_update();         // Updates actions based on the current state

#endif
