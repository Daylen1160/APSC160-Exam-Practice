// ---------------------------------------------------
// Pin assignments
// ---------------------------------------------------
const int GREEN = 4;     // Green LED connected to pin 4
const int YELLOW = 3;    // Yellow LED connected to pin 3
const int RED = 2;       // Red LED connected to pin 2

// ---------------------------------------------------
// Timing constants (in milliseconds)
// ---------------------------------------------------
const int DELAY_GREEN = 15000;   // Green light duration: 15 seconds
const int DELAY_YELLOW = 3000;   // Yellow light duration: 3 seconds
const int DELAY_RED = 15000;     // Red light duration: 15 seconds

// ---------------------------------------------------
// Setup function: Configures LED pins as outputs
// ---------------------------------------------------
void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

// ---------------------------------------------------
// Main loop: Cycles through green → yellow → red with delays
// ---------------------------------------------------
void loop()
{
  green_light();           // Turn on green light
  delay(DELAY_GREEN);      // Keep green on

  yellow_light();          // Turn on yellow light
  delay(DELAY_YELLOW);     // Keep yellow on

  red_light();             // Turn on red light
  delay(DELAY_RED);        // Keep red on
}

// ---------------------------------------------------
// Turn on GREEN, turn off YELLOW and RED
// ---------------------------------------------------
void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

// ---------------------------------------------------
// Turn on YELLOW, turn off GREEN and RED
// ---------------------------------------------------
void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

// ---------------------------------------------------
// Turn on RED, turn off GREEN and YELLOW
// ---------------------------------------------------
void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
