#ifndef lcd_states_included
#define lcd_states_included

void lcd_init();                           // Initialize LCD
void lcd_update_time(unsigned int tenths); // Update time display
void lcd_animation_dual_balls();           // Two vertically moving balls animation

#endif // lcd_states_included

