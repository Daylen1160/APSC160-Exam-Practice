#define SIZE 6  // Total number of LEDs in the sequence

const int LED[] = {13, 12, 11, 10, 9, 8};  // Array holding the digital pins for each LED

// Function prototypes for forward and backward LED sequences
void forwardSeq();
void backwardSeq();

// -------------------------------
// Setup: Configure LED pins and Serial
// -------------------------------
void setup()
{  
  // Initialize all LED pins as OUTPUT
  for(int count = 0; count < SIZE; count++)
  {
    pinMode(LED[count], OUTPUT);
  }

  // Initialize Serial communication for printing LED status
  Serial.begin(9600);
}

// -------------------------------
// Run forward and backward LED sequences
// -------------------------------
void loop()
{
    // Run the forward LED sequence
  forwardSeq();

  // Run the backward LED sequence
  backwardSeq();

  // Print a blank line to separate sequences in Serial Monitor
  Serial.println();
}

// -------------------------------
// Lights LEDs from first to last
// -------------------------------
void forwardSeq()
{
  // Loop through each LED from first to last
  for(int count = 0; count < SIZE; count++)
  {    
    // Turn ON the current LED and turn OFF all others
    for(int led = 0; led < SIZE; led++)
    {
      if(count == led)
      {
        digitalWrite(LED[led], HIGH);  // Turn ON the current LED

        // Print which LED is ON
        Serial.print("LED ");
        Serial.print(led + 1);
        Serial.println(" is ON.");
      }
      else
      {
        digitalWrite(LED[led], LOW);  // Turn OFF all other LEDs
      }
    }

    // Wait 1 second before moving to the next LED
    delay(1000);
  }
}

// -------------------------------
// Lights LEDs from last to first
// -------------------------------
void backwardSeq()
{
  // Loop through each LED from last to first
  for(int count = SIZE - 1; count >= 0; count--)
  {    
    // Turn ON the current LED and turn OFF all others
    for(int led = 0; led < SIZE; led++)
    {
      if(count == led)
      {
        digitalWrite(LED[led], HIGH);  // Turn ON the current LED

        // Print which LED is ON
        Serial.print("LED ");
        Serial.print(led + 1);
        Serial.println(" is ON.");
      }
      else
      {
        digitalWrite(LED[led], LOW);  // Turn OFF all other LEDs
      }
    }

    // Wait 1 second before moving to the next LED
    delay(1000);
  }
}
