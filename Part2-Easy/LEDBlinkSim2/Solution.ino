// Total number of LEDs
const int numLEDs = 10;

// Array storing the pin numbers for each LED (pins 13 to 4)
const int LED[numLEDs] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4};

// Function prototype for backward LED sequence
void blinkLED();

// ......................................
// Defines LED pins and initializes serial communication
// ......................................
void setup()
{
  // Set each LED pin as OUTPUT
  for(int count = 0; count < numLEDs; count++)
  {
    pinMode(LED[count], OUTPUT);
  }
  
  // Initialize Serial Monitor at 9600 baud rate
  Serial.begin(9600);
}

// ......................................
// Performs forward sequence and calls function for backward sequence
// ......................................
void loop()
{
  // Quick forward sequence: turn LEDs ON from LED #1 to LED #10
  for(int count = 0; count < numLEDs; count++)
  {
    digitalWrite(LED[count], HIGH); // Turn current LED ON
    Serial.print("LED #");
    Serial.print(count + 1);
    Serial.println(" is On."); // Print LED status to Serial Monitor
    delay(100); // Short delay of 0.1 second
  }
  
  Serial.print("\n"); // Add newline for clarity in Serial Monitor
  
  // Call function for backward sequences
  blinkLED();
  
  Serial.print("\n"); // Add newline for clarity in Serial Monitor
  
  delay(100); // Short pause before next iteration of loop
}

// ......................................
// Function to perform backward sequences
// ......................................
void blinkLED()
{
  // Loop through each LED from LED #10 to LED #1
  for(int ledID = numLEDs - 1; ledID >= 0; ledID--)
  {
    // Inner loop controls each LED in backward order
    for(int count = numLEDs - 1; count >= 0; count--)
    {
      if(count == ledID)
      {
        // Turn ON the LED corresponding to current step
        digitalWrite(LED[count], HIGH);
        Serial.print("LED #");
        Serial.print(count + 1);
        Serial.println(" is On."); // Print active LED status
        delay(100); // Short delay for quick backward sequence
      }
      
      else
      {
        // Turn OFF all other LEDs
        digitalWrite(LED[count], LOW);
        delay(100); // Delay to keep timing consistent
      }
    }
  }
}
