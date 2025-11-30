// Pin definitions for the LEDs
#define BLUE_LED_PIN 8       // Blue LED indicates cold weather
#define GREEN_LED_PIN 5      // Green LED indicates moderate weather
#define RED_LED_PIN 2        // Red LED indicates hot weather

// Pin definition for the temperature sensor
#define TEMP_SENSOR_PIN A0   // Analog input pin for temperature sensor

// Temperature bounds
#define LOWER_TEMP_BOUND 0   // Lower temperature threshold in °C
#define UPPER_TEMP_BOUND 40  // Upper temperature threshold in °C

// Constants for analog-to-voltage conversion
#define MAX_VOLTAGE_VAL 5.0  // Maximum voltage output from sensor
#define MAX_ANALOG_VAL 1023.0 // Maximum analog reading from sensor

// Variable to store the raw analog reading
int sensorValue = 0;

// Function prototypes
float findTemp(float voltageValue);      // Computes temperature in °C from sensor voltage
void turnOnLED(float temperatureValue);  // Controls LEDs based on temperature

// ----------------------------
// Defines temperature sensor and LED pins while initializing Serial communication.
// ----------------------------
void setup()
{
  // Configure temperature sensor pin as INPUT
  pinMode(TEMP_SENSOR_PIN, INPUT);

  // Configure LED pins as OUTPUT
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Initialize Serial Monitor communication
  Serial.begin(9600);
}

// ----------------------------
// Performs analog to digital conversion and calls functions for temperature and LEDs.
// ----------------------------
void loop()
{
  float voltageValue;      // Variable to store sensor voltage
  float temperatureValue;  // Variable to store computed temperature

  // Read the analog value from the temperature sensor
  sensorValue = analogRead(TEMP_SENSOR_PIN);

  // Convert analog reading to voltage (0–5V)
  voltageValue = sensorValue * (MAX_VOLTAGE_VAL / MAX_ANALOG_VAL);

  // Convert voltage to temperature in °C
  temperatureValue = findTemp(voltageValue);

  // Update LEDs based on temperature
  turnOnLED(temperatureValue);

  // Short delay before next reading
  delay(100);
}

// ----------------------------
// Converts sensor voltage to temperature in °C and prints it
// ----------------------------
float findTemp(float voltageValue)
{
  float buffer;             // Intermediate variable for calculation
  float temperatureValue;   // Final temperature value in °C

  // Convert voltage to millivolts and apply sensor offset
  buffer = (voltageValue * 1000.0) - 500.0;

  // Convert millivolts to temperature in °C
  temperatureValue = buffer / 10.0;

  // Print temperature to Serial Monitor
  Serial.print("The temperature is ");
  Serial.print(temperatureValue);
  Serial.print(" \xb0");  // Degree symbol
  Serial.print("C. ");

  return temperatureValue;  // Return temperature to loop
}

// ----------------------------
// Turns on the LED corresponding to the temperature range and prints weather
// ----------------------------
void turnOnLED(float temperatureValue)
{
  if(temperatureValue < LOWER_TEMP_BOUND)
  {
    // Cold: Blue LED ON, others OFF
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    // Print weather to Serial Monitor
    Serial.print("The weather is cold.\n\n");
    delay(1000);
  }
  else if(temperatureValue > UPPER_TEMP_BOUND)
  {
    // Hot: Red LED ON, others OFF
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    // Print weather to Serial Monitor
    Serial.print("The weather is hot.\n\n");
    delay(1000);
  }
  else
  {
    // Moderate: Green LED ON, others OFF
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    // Print weather to Serial Monitor
    Serial.print("The weather is moderate.\n\n");
    delay(1000);
  }
}
