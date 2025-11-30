// Pin definitions for the RGB LED
#define RGB_RED 11
#define RGB_BLUE 10
#define RGB_GREEN 9

// Pin definitions for the potentiometers controlling each color channel
#define POT_RED A0
#define POT_BLUE A1
#define POT_GREEN A2

// Constants for maximum and minimum PWM signals
const int MAX_SIGNAL = 255;
const int MIN_SIGNAL = 0;

// Variable to store the raw analog reading from potentiometers
int sensorValue = 0;

// Variables to store mapped PWM values for each color channel
int outputValueRed;
int outputValueBlue;
int outputValueGreen;

// Function prototypes
void toggleRed();
void toggleBlue();
void toggleGreen();
void toggleRGB(int outputValueRed, int outputValueBlue, int outputValueGreen);

// ----------------------------
// Defines RGB LED and potentiometer pins while initializing Serial communication
// ----------------------------
void setup()
{
  // Configure RGB LED pins as OUTPUT
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  
  // Configure potentiometer pins as INPUT
  pinMode(POT_RED, INPUT);
  pinMode(POT_BLUE, INPUT);
  pinMode(POT_GREEN, INPUT);
  
  // Initialize Serial Monitor at 9600 baud
  Serial.begin(9600);
}

// ----------------------------
// Reads RED, BLUE & GREEN LED channels
// ----------------------------
void loop()
{
  // Read and update the Red LED channel
  toggleRed();
  
  // Read and update the Blue LED channel
  toggleBlue();
  
  // Read and update the Green LED channel
  toggleGreen();
  
  // Determine and print the current RGB color based on PWM values
  toggleRGB(outputValueRed, outputValueBlue, outputValueGreen);
  
  // Short delay between updates
  delay(100);
}

// ----------------------------
// Reads Red potentiometer and sets Red LED
// ----------------------------
void toggleRed()
{
  sensorValue = analogRead(POT_RED);        // Read analog value (0-1023)
  outputValueRed = sensorValue / 4;         // Map to PWM (0-255)
  analogWrite(RGB_RED, outputValueRed);     // Set Red LED brightness
}

// ----------------------------
// Reads Blue potentiometer and sets Blue LED
// ----------------------------
void toggleBlue()
{
  sensorValue = analogRead(POT_BLUE);       // Read analog value (0-1023)
  outputValueBlue = sensorValue / 4;        // Map to PWM (0-255)
  analogWrite(RGB_BLUE, outputValueBlue);   // Set Blue LED brightness
}

// ----------------------------
// Reads Green potentiometer and sets Green LED
// ----------------------------
void toggleGreen()
{
  sensorValue = analogRead(POT_GREEN);      // Read analog value (0-1023)
  outputValueGreen = sensorValue / 4;       // Map to PWM (0-255)
  analogWrite(RGB_GREEN, outputValueGreen); // Set Green LED brightness
}

// ----------------------------
// Determines and prints current RGB color based on PWM values
// ----------------------------
void toggleRGB(int outputValueRed, int outputValueBlue, int outputValueGreen)
{
  if(outputValueRed == MAX_SIGNAL && outputValueBlue == MIN_SIGNAL && outputValueGreen == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Red.\n");
    delay(1000);
  }
  else if(outputValueBlue == MAX_SIGNAL && outputValueGreen == MIN_SIGNAL && outputValueRed == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Blue.\n");
    delay(1000);
  }
  else if(outputValueGreen == MAX_SIGNAL && outputValueRed == MIN_SIGNAL && outputValueBlue == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Green.\n");
    delay(1000);
  }
  else if(outputValueRed == MAX_SIGNAL && outputValueBlue == MAX_SIGNAL && outputValueGreen == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Purple.\n");
    delay(1000);
  }
  else if(outputValueBlue == MAX_SIGNAL && outputValueGreen == MAX_SIGNAL && outputValueRed == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Turquoise.\n");
    delay(1000);
  }
  else if(outputValueGreen == MAX_SIGNAL && outputValueRed == MAX_SIGNAL && outputValueBlue == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Yellow.\n");
    delay(1000);
  }
  else if(outputValueGreen == MAX_SIGNAL && outputValueRed == MAX_SIGNAL && outputValueBlue == MAX_SIGNAL)
  {
    Serial.println("The RGB LED is White.\n");
    delay(1000);
  }
  else if(outputValueGreen == MIN_SIGNAL && outputValueRed == MIN_SIGNAL && outputValueBlue == MIN_SIGNAL)
  {
    Serial.println("The RGB LED is Off.\n");
    delay(1000);
  }
}
