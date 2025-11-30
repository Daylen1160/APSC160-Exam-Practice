#define numLEDs 8

// LED pins for Display 0
#define A0 A2
#define B0 A3
#define C0 A4
#define D0 A5
#define E0 2
#define F0 3
#define G0 4
#define DP0 5

// LED pins for Display 1
#define A1 6
#define B1 7
#define C1 8
#define D1 9
#define E1 10
#define F1 11
#define G1 12
#define DP1 13

// Arrays containing the LED pins for each display
const int LEDs0[numLEDs] = {A0, B0, C0, D0, E0, F0, G0, DP0};
const int LEDs1[numLEDs] = {A1, B1, C1, D1, E1, F1, G1, DP1};

// Character patterns for Display 0 (example character)
const int display0[numLEDs][numLEDs] = {
  {0, 0, 0, 1, 0, 0, 0, 1},
  {1, 1, 1, 0, 0, 0, 1, 1},
  {1, 0, 0, 0, 1, 0, 0, 1},
  {0, 1, 0, 1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 1},
  {0, 0, 0, 1, 0, 0, 0, 1},
  {0, 0, 0, 1, 0, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 1, 0}
};

// Character patterns for Display 1 (example character)
const int display1[numLEDs][numLEDs] = {
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 1},
  {0, 0, 0, 1, 1, 1, 1, 0}
};

// ---------------------------------------------------
// Function Prototypes
// ---------------------------------------------------
void toggleLEDs(const int display0[], const int display1[]);

// ---------------------------------------------------
// Initialize all LED pins as OUTPUT
// ---------------------------------------------------
void setup()
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    pinMode(LEDs0[constant], OUTPUT);  // Set Display 0 LED pins as OUTPUT
    pinMode(LEDs1[constant], OUTPUT);  // Set Display 1 LED pins as OUTPUT
  }
}

// ---------------------------------------------------
// Cycle through each row of both displays
// ---------------------------------------------------
void loop()
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    toggleLEDs(display0[constant], display1[constant]);  // Update both displays
    delay(1000);                                         // Wait 1 second between rows
  }
  
  delay(100);  // Small delay for loop stability
}

// ---------------------------------------------------
// Update both displays simultaneously
// ---------------------------------------------------
void toggleLEDs(const int display0[], const int display1[])
{
  for(int constant = 0; constant < numLEDs; constant++)
  {
    digitalWrite(LEDs0[constant], display0[constant]);  // Update Display 0 LED
    digitalWrite(LEDs1[constant], display1[constant]);  // Update Display 1 LED
  }
}
