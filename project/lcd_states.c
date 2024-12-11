its[0] || ball2Pos >= rowLimits[1]) {
  ball2Vel = -ball2Vel;
				    }

// Draw the balls at the new positions
fillRectangle(5, ball1Pos, 10, 10, COLOR_GREEN); // Left ball
fillRectangle(screenWidth - 15, ball2Pos, 10, 10, COLOR_RED); // Right ball

// Redraw stopwatch label and time
drawString5x7(20, 20, "RUNNING", COLOR_WHITE, COLOR_BLUE);
drawString5x7(20, 40, "MM:SS.T", COLOR_WHITE, COLOR_BLUE); // Placeholder for time
}

// Initialize the LCD
void lcd_init() {
  configureClocks();
  lcd_init();
  clearScreen(COLOR_BLUE);
}

// Update time on the LCD
void lcd_update_time(unsigned int tenths) {
  char time_str[9];
  unsigned int minutes = tenths / 600;
  unsigned int seconds = (tenths / 10) % 60;
  unsigned int tenths_digit = tenths % 10;

  // Format time string as MM:SS.T
  time_str[0] = '0' + (minutes / 10);
  time_str[1] = '0' + (minutes % 10);
  time_str[3] = '0' + (seconds / 10);
  time_str[4] = '0' + (seconds % 10);
  time_str[6] = '0' + tenths_digit;
  time_str[7] = '\0';

  // Display time string
  drawString5x7(20, 40, time_str, COLOR_WHITE, COLOR_BLUE);
}

