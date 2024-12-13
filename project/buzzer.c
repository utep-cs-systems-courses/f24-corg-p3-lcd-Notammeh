#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void buzzer_init()
{
  /*
     Direct timer A output "TA0.1" to P2.6.

      According to table 21 from data sheet:

        P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero

        P2SEL.6 must be 1

      Also: P2.6 direction must be output
  */
  timerAUpmode(); /* used to drive speaker */

  P2SEL2 &= ~(BIT6 | BIT7);

  P2SEL &= ~BIT7;

  P2SEL |= BIT6;

  P2DIR = BIT6; /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; /* one half cycle */
}

void musica()

{

  
  int notes[] = {C6, C6, D6, C6, D6, E6, C6, C6, D6, C6, G6, D6, C6, C6, C7, A6, D6, E6, D6};
  int durations[] = {500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 1000, 2000}; 

  int total_notes = sizeof(notes) / sizeof(notes[0]);
  for (int i = 0; i < total_notes; i++)

    {

      buzzer_set_period(notes[i]);

      __delay_cycles(2500000);

      buzzer_set_period(0);

      __delay_cycles(250000);
    }
}

void musica2(){

  
  int jingle[] = {C5, E5, G5, E5, C5, E5, G5, E5, A4, C5, E5, C5, A4, A4, C5, A4};
  int totalNotes =sizeof(jingle)/sizeof(jingle[0]);//this is used to get the number of notes 
  for(int i=0; i<totalNotes;i++){//used to iterate through array

    buzzer_set_period(jingle[i]);//play note
    __delay_cycles(2000000);//hold note
    buzzer_set_period(0);//stop the note
    __delay_cycles(2000000);//used to create a short pause between notes
  }

  buzzer_set_period(0);//this is used to make sure the buzzer turns off

}//end of musica2

void musica3(){
  int jingle[] = {0, A4, 0, E5, 0, E5, 0, E5, 0, 0, E5, 0, 0, A4, 0, A4};
  int totalNotes =sizeof(jingle)/sizeof(jingle[0]);
  for(int i=0; i<totalNotes;i++){
    buzzer_set_period(jingle[i]);//play note
    __delay_cycles(2000000);//hold note
    buzzer_set_period(0);//stop the note
    __delay_cycles(2000000);//used to create a short pause between notes
  }
  buzzer_set_period(0);//this is used to make sure the buzzer turns off

}//end of song4

void musica_update()

{

  static int count = 0;

  count++;

  if (count == 5)
    {
      musica2();

      count = 0;
    }
}


