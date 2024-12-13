#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"
#include "buzzer.h"
#include "led.h"

int lcd_red = 0; // State variable to toggle between displays

// Function to display the start screen
void lcd_start() {
  clearScreen(COLOR_BLACK);

  // Display "Open me!"
  drawString8x12(30, 50, "Open me!", COLOR_PINK, COLOR_BLACK);

  u_char width = screenWidth, height = screenHeight;

  // Draw main body of the envelope as a large white rectangle
  int envelopeX = 5; // X-coordinate start of the envelope
  int envelopeY = 70; // Y-coordinate start of the envelope
  int envelopeWidth = 120; // Width of the envelope
  int envelopeHeight = 60; // Height of the envelope
  fillRectangle(envelopeX, envelopeY, envelopeWidth, envelopeHeight, COLOR_WHITE);

  // Draw pink triangle for the flap
  int triangleHeight = (3 * envelopeHeight) / 4; // Height of the triangle is 3/4 the height of the envelope
  for (int row = 0; row < triangleHeight; row++) {
    int triangleWidth = envelopeWidth * (triangleHeight - row) / triangleHeight; // Calculate width of each row
    int startX = envelopeX + (envelopeWidth - triangleWidth) / 2; // Center the triangle row
    fillRectangle(startX, envelopeY + row, triangleWidth, 1, COLOR_PINK);
  }
}

// Function to display the siren-like alternating screens
void lcd_siren() {
  if (lcd_red) {
    clearScreen(COLOR_BLACK); // Clear screen with black

    // Display "CHRISTMAS"
    drawString8x12(20, 120, "CHRISTMAS", COLOR_PINK, COLOR_BLACK);

    int startX = 55;   // Horizontal start position
    int startY = 20;   // Vertical start position
    int rectSize = 10; // Size of each rectangle

    // Draw the heart shape
    fillRectangle(startX - 2 * rectSize, startY, rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - rectSize, startY, rectSize, rectSize, COLOR_RED);
    fillRectangle(startX + rectSize, startY, rectSize, rectSize, COLOR_RED);
    fillRectangle(startX + 2 * rectSize, startY, rectSize, rectSize, COLOR_RED);

    fillRectangle(startX - 3 * rectSize, startY + rectSize, 7 * rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - 4 * rectSize, startY + 2 * rectSize, 9 * rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - 3 * rectSize, startY + 3 * rectSize, 7 * rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - 2 * rectSize, startY + 4 * rectSize, 5 * rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - rectSize, startY + 5 * rectSize, 3 * rectSize, rectSize, COLOR_RED);
    fillRectangle(startX - rectSize + 5, startY + 6 * rectSize, 2 * rectSize, rectSize, COLOR_RED);

    musica3(50); // Play music or sound
    lcd_red = 0; // Toggle state
  } else {
    clearScreen(COLOR_WHITE); // Clear screen with white

    // Display "MERRY"
    drawString8x12(45, 120, "MERRY", COLOR_BLACK, COLOR_WHITE);

    // Draw a simple star
    u_char xCenter = screenWidth / 2;  // Center of the screen
    u_char yCenter = screenHeight / 2; // Center of the screen
    

    // Draw horizontal line of the star
    fillRectangle(xCenter -20, yCenter - 2, 40, 5, COLOR_CYAN);

    // Draw vertical line of the star
    fillRectangle(xCenter - 2, yCenter - 20, 5, 40, COLOR_CYAN);

    // Draw diagonal lines of the star
    fillRectangle(xCenter - 14, yCenter - 14, 30, 5, COLOR_CYAN); // Top-left to bottom-right
    fillRectangle(xCenter - 14, yCenter + 10, 30, 5, COLOR_CYAN); // Bottom-left to top-right

    musica3(50); // Play music or sound
    lcd_red = 1; // Toggle state
  }
}
// Function to update the siren state periodically
void lcd_siren_update() {
  static int count = 0;

  count++;
  if (count == 100) {
    lcd_siren(); // Switch displays every 100 cycles
    count = 0;
  }
}
