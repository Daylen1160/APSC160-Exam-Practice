#define LED_BLUE 13        // Blue LED connected to digital pin 13
#define LED_GREEN 7        // Green LED connected to digital pin 7

#define BUTTON 2           // Pushbutton connected to digital pin 2

int buttonState = 0;       // Stores the current state of the button (HIGH or LOW)
int numPress = 0;          // Counts how many times the button has been pressed

// Function Prototypes
void toggleLED(int buttonState);  // Decides which LED should blink based on press count
void blinkBlue(int numPress);     // Blinks the blue LED numPress times
void blinkGreen(int numPress);    // Blinks the green LED numPress times

// ----------------------------
// Configures LED and button while initializing Serial communication.
// ----------------------------
void setup()
{
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(BUTTON, INPUT);

  Serial.begin(9600);   // Start Serial Monitor output
}


// ----------------------------
// Reads button state and calls toggle LED function
// ----------------------------
void loop()
{
  buttonState = digitalRead(BUTTON);  
  toggleLED(buttonState);           
  delay(100);                        // Debounce delay
}


// ----------------------------
// Decides LED behavior based on button state
// ----------------------------
void toggleLED(int buttonState)
{
  if(buttonState == HIGH)
  {
    numPress++;  // Count each button press

    if(numPress % 2 == 1)     // Odd press
    {
      blinkBlue(numPress);
    }
    else if(numPress % 2 == 0) // Even press
    {
      blinkGreen(numPress);
    }

    Serial.println();  // Print a blank line for readability
  }

  else  // Button NOT pressed
  {
    digitalWrite(LED_BLUE, LOW);   // Keep both LEDs OFF
    digitalWrite(LED_GREEN, LOW);
  }
}


// ----------------------------
// Blinks the blue LED numPress times, 1 second ON, 1 second OFF, while printing a message each blink
// ----------------------------
void blinkBlue(int numPress)
{
  for(int count = 0; count < numPress; count++)
  {	
    Serial.println("The Blue LED is blinking!");

    digitalWrite(LED_BLUE, HIGH);
    delay(1000);

    digitalWrite(LED_BLUE, LOW);
    delay(1000);
  }
}


// ----------------------------
// Blinks the green LED numPress times, 1 second ON, 1 second OFF, while printing a message each blink
// ----------------------------
void blinkGreen(int numPress)
{
  for(int count = 0; count < numPress; count++)
  {
    Serial.println("The Green LED is blinking!");

    digitalWrite(LED_GREEN, HIGH);
    delay(1000);

    digitalWrite(LED_GREEN, LOW);
    delay(1000);
  }
}
