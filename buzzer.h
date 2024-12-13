#ifndef buzzer_included

#define buzzer_included
#define C6 1108.73
#define F5 739.99
#define D6 1174.66
#define E6  1318.51  // E note in the 6th octave
#define G6  1567.98  // G note in the 6th octave
#define A6  1760.00  // A note in the 6th octave
#define B6  1975.53  
#define C7  2093.00  
#define D7  2349.32  
#define E7  2637.02  
#define F7  2793.83 
#define G7  3135.96  

void buzzer_init();

void buzzer_set_period(short cycles);

void musica();

void musica_update();



#endif
