#define SIZE 6                       // Number of LEDs in the sequence
#define POT A0                        // Analog pin connected to the potentiometer

const int LED[] = {13, 12, 11, 10, 9, 8, 7};  // Array of LED pins

int sensorValue = 0;                    // Variable to store the potentiometer reading
float buffer;                            // Variable to store the mapped delay time for LED speed

// Function declarations
void forwardSeq();                       // Function to run LED sequence forward (1 → n)
void backwardSeq();                      // Function to run LED sequence backward (n → 1)
void lightSpeed();                       // Function to read potentiometer and set LED delay

// ---------------------------
// Configures the LEDs
// ---------------------------
void setup()
{
  // Initialize all LEDs as OUTPUT
  for(int count = 0; count < SIZE; count++)
  {
    pinMode(LED[count], OUTPUT);
  }
}

// ---------------------------
// Performs LED sequence at appropriate speed
// ---------------------------
void loop()
{
  // Continuously run the LED sequence forward and backward
  forwardSeq();
  backwardSeq();
}

// ---------------------------
// Lights the LEDs in a forward sequence, from the first to the last LED.
// ---------------------------
void forwardSeq()
{
  for(int count = 0; count < SIZE - 1; count++)
  {    
    for(int led = 0; led < SIZE - 1; led++)
    {
      if(count == led)
      {
        digitalWrite(LED[count], HIGH);  // Turn ON the current LED
      }
      else
      {
        digitalWrite(LED[led], LOW);     // Turn OFF all other LEDs
      }
    }
    
    lightSpeed();  // Adjust speed based on potentiometer
  }
}

// ---------------------------
// Lights the LEDs in a backward sequence, from the last to the first LED.
// ---------------------------
void backwardSeq()
{
  for(int count = SIZE - 1; count > 0; count--)
  {    
    for(int led = SIZE - 1; led > 0; led--)
    {
      if(count == led)
      {
        digitalWrite(LED[count], HIGH);  // Turn ON the current LED
      }
      else
      {
        digitalWrite(LED[led], LOW);     // Turn OFF all other LEDs
      }
    }
    
    lightSpeed();  // Adjust speed based on potentiometer
  }
}

// ---------------------------
// Reads potentiometer value and calculates corresponding delay for LED sequence speed
// ---------------------------
void lightSpeed()
{
  sensorValue = analogRead(POT);                 // Read potentiometer analog value
  buffer = ((sensorValue / 1023.0) * 900) + 100; // Map to 100–1000ms delay
  delay(buffer);                                 // Delay for calculated speed
}
