// ---------------------------------------------------
// Define number of LEDs in the 7-segment display
// ---------------------------------------------------
#define numLEDs 8

// ---------------------------------------------------
// Define the digital pins connected to each segment
// of the 7-segment display
// ---------------------------------------------------
#define A0 A2
#define B0 A3
#define C0 A4
#define D0 A5
#define E0 2
#define F0 3
#define G0 4
#define DP0 5

// ---------------------------------------------------
// Array of LED pins for easier iteration
// ---------------------------------------------------
const int LEDs0[numLEDs] = {A0, B0, C0, D0, E0, F0, G0, DP0};

// ---------------------------------------------------
// Hardcoded 8x8 array representing the characters
// 'A', 'P', 'S', 'C', '1', '6', '0', '.'
// Each row represents one character
// Each column represents a segment (A-G + DP)
// 1 = LED ON, 0 = LED OFF
// ---------------------------------------------------
const int display0[numLEDs][numLEDs] = {
  {0, 0, 0, 1, 0, 0, 0, 1},  // 'A'
  {0, 0, 1, 1, 0, 0, 0, 1},  // 'P'
  {0, 1, 0, 0, 1, 0, 0, 1},  // 'S'
  {0, 1, 1, 0, 0, 0, 1, 1},  // 'C'
  {1, 0, 0, 1, 1, 1, 1, 1},  // '1'
  {0, 1, 0, 0, 0, 0, 0, 1},  // '6'
  {0, 0, 0, 0, 0, 0, 1, 1},  // '0'
  {0, 0, 0, 0, 0, 0, 0, 1}   // '.'
};

// ---------------------------------------------------
// Function prototype
// ---------------------------------------------------
void toggleLEDs(const int display0[]);

// ---------------------------------------------------
// Configure each LED pin as OUTPUT
// ---------------------------------------------------
void setup()
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    pinMode(LEDs0[constant], OUTPUT);  // Set each segment pin as OUTPUT
  }
}

// ---------------------------------------------------
// Continuously cycle through each character
// ---------------------------------------------------
void loop()
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    toggleLEDs(display0[constant]);   // Display the current character
    delay(1000);                       // Wait 1 second before next character
  }

  delay(100);  // Small delay between cycles (optional)
}

// ---------------------------------------------------
// Updates the LEDs of the display based on the
// current character array passed as argument
// ---------------------------------------------------
void toggleLEDs(const int display0[])
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    digitalWrite(LEDs0[constant], display0[constant]);  // Turn LED ON or OFF
  }
}
