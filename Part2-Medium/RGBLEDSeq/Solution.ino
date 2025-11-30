#define NUM_LEDS 3                  // Define the number of LEDs in the RGB LED
#define MAX_BRIGHTNESS 255          // Maximum PWM value for full brightness
#define MIN_BRIGHTNESS 0            // Minimum PWM value to turn off LED

const int LED[NUM_LEDS] = {11, 10, 9};  // PWM pins for Red, Blue, Green LEDs

// Function prototypes
void generateRandom(int randomLED[NUM_LEDS]);
void toggleRED();
void toggleBLUE();
void toggleGREEN();

// ---------------------------------------------
// Defines output pins and serial communication
// ----------------------------------------------
void setup()
{
  // Configure each RGB LED pin as OUTPUT
  for(int count = 0; count < NUM_LEDS; count++)
  {
    pinMode(LED[count], OUTPUT);
  }

  // Initialize Serial communication at 9600 bps
  Serial.begin(9600);
}

// ---------------------------------------------
// Loops through random sequence of RGB LED
// ----------------------------------------------
void loop()
{
  int randomLED[NUM_LEDS];               // Array to store randomly generated LED sequence

  // -------------------------------
  // Generate a random sequence
  // -------------------------------
  generateRandom(randomLED);

  // -------------------------------
  // Display each LED color based on random sequence
  // -------------------------------
  for(int count = 0; count < NUM_LEDS; count++)
  {
    // Check if the current LED is RED
    if(randomLED[count] == LED[0])
    {
      toggleRED();                        // Turn on RED LED and turn off others
    }
    // Check if the current LED is BLUE
    else if(randomLED[count] == LED[1])
    {
      toggleBLUE();                       // Turn on BLUE LED and turn off others
    }
    // Check if the current LED is GREEN
    else if(randomLED[count] == LED[2])
    {
      toggleGREEN();                      // Turn on GREEN LED and turn off others
    }

    // Wait for 1 second before moving to the next LED
    delay(1000);
  }

  // Print a blank line to separate sequences in the Serial Monitor
  Serial.println();
}

// ---------------------------------------------
// Generate a random sequence of LEDs for Red, Blue, Green
// ----------------------------------------------
void generateRandom(int randomLED[NUM_LEDS])
{
  for(int count = 0; count < NUM_LEDS; count++)
  {
    // Assign a random LED pin (9, 10, 11) to each array element
    randomLED[count] = random(9, 12);
  }
}

// ---------------------------------------------
// Turn on RED LED and turn off others
// ----------------------------------------------
void toggleRED()
{
  analogWrite(LED[0], MAX_BRIGHTNESS);     // RED ON
  analogWrite(LED[1], MIN_BRIGHTNESS);     // BLUE OFF
  analogWrite(LED[2], MIN_BRIGHTNESS);     // GREEN OFF

  // Print status to Serial Monitor
  Serial.println("The RED LED is On.");
}

// ---------------------------------------------
// Turn on BLUE LED and turn off others
// ----------------------------------------------
void toggleBLUE()
{
  analogWrite(LED[0], MIN_BRIGHTNESS);     // RED OFF
  analogWrite(LED[1], MAX_BRIGHTNESS);     // BLUE ON
  analogWrite(LED[2], MIN_BRIGHTNESS);     // GREEN OFF

  // Print status to Serial Monitor
  Serial.println("The BLUE LED is On.");
}

// ---------------------------------------------
// Turn on GREEN LED and turn off others
// ----------------------------------------------
void toggleGREEN()
{
  analogWrite(LED[0], MIN_BRIGHTNESS);     // RED OFF
  analogWrite(LED[1], MIN_BRIGHTNESS);     // BLUE OFF
  analogWrite(LED[2], MAX_BRIGHTNESS);     // GREEN ON

  // Print status to Serial Monitor
  Serial.println("The GREEN LED is On.");
}
