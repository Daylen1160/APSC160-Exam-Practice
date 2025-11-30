// ---------------------------------------------------
// Variables
// ---------------------------------------------------
int ledBrightness = 128;  // Initial brightness of the LED
int buttonState1 = 0;     // State of Button 1
int buttonState2 = 0;     // State of Button 2

// ---------------------------------------------------
// setup()
// Runs once at startup
// Configures pushbutton and LED pins
// ---------------------------------------------------
void setup()
{
  pinMode(BUTTON1, INPUT);   // Button 1
  pinMode(BUTTON2, INPUT);   // Button 2
  pinMode(LED, OUTPUT);  // LED
}

// ---------------------------------------------------
// loop()
// Runs repeatedly
// Reads button states, adjusts brightness, and updates LED
// ---------------------------------------------------
void loop()
{
  buttonState1 = digitalRead(BUTTON1);  // Read Button 1
  buttonState2 = digitalRead(BUTTON2);  // Read Button 2

  if(buttonState1 == LOW)
  {
    decreaseBrightness();          // Decrease LED brightness
  }
  else if(buttonState2 == LOW)
  {
    increaseBrightness();          // Increase LED brightness
  }

  ledBrightness = constrain(ledBrightness, 0, 255);  // Keep brightness in range
  analogWrite(LED, ledBrightness);                     // Update LED PWM
  delay(20);                                         // Smooth adjustment
}

// ---------------------------------------------------
// Decreases the LED brightness by 1
// ---------------------------------------------------
void decreaseBrightness()
{
  ledBrightness--;
}

// ---------------------------------------------------
// Increases the LED brightness by 1
// ---------------------------------------------------
void increaseBrightness()
{
  ledBrightness++;
}
