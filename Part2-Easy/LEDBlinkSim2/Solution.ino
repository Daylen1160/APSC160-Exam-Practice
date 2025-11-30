#define LED1 9
#define LED2 8
#define LED3 7
#define LED4 6
#define LED5 5
#define LED6 4
#define LED7 3
#define LED8 2

// ----------------------------
// Configures LED pins and initializes serial communication
// ----------------------------
void setup()
{
  // Configure left-side LEDs as OUTPUT
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // Configure right-side LEDs as OUTPUT
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

// ----------------------------
// Controls the sequence of turning LEDs ON and OFF in opposite pairs
// ----------------------------
void loop()
{
  // --- TURN ON SEQUENCE (inward) ---

  // Turn on outermost pair (LED1 and LED8)
  digitalWrite(LED1, HIGH);
  Serial.println("LED #1 is On.");
  digitalWrite(LED8, HIGH);
  Serial.println("LED #8 is On.\n");
  delay(1000);

  // Turn on next inner pair (LED2 and LED7)
  digitalWrite(LED2, HIGH);
  Serial.println("LED #2 is On.");
  digitalWrite(LED7, HIGH);
  Serial.println("LED #7 is On.\n");
  delay(1000);

  // Turn on next inner pair (LED3 and LED6)
  digitalWrite(LED3, HIGH);
  Serial.println("LED #3 is On.");
  digitalWrite(LED6, HIGH);
  Serial.println("LED #6 is On.\n");
  delay(1000);

  // Turn on innermost pair (LED4 and LED5)
  digitalWrite(LED4, HIGH);
  Serial.println("LED #4 is On.");
  digitalWrite(LED5, HIGH);
  Serial.println("LED #5 is On.\n");
  delay(1000);


  // --- TURN OFF SEQUENCE (outward) ---

  // Turn off innermost pair (LED4 and LED5)
  digitalWrite(LED4, LOW);
  Serial.println("LED #4 is Off.");
  digitalWrite(LED5, LOW);
  Serial.println("LED #5 is Off.\n");
  delay(1000);

  // Turn off next inner pair (LED3 and LED6)
  digitalWrite(LED3, LOW);
  Serial.println("LED #3 is Off.");
  digitalWrite(LED6, LOW);
  Serial.println("LED #6 is Off.\n");
  delay(1000);

  // Turn off next inner pair (LED2 and LED7)
  digitalWrite(LED2, LOW);
  Serial.println("LED #2 is Off.");
  digitalWrite(LED7, LOW);
  Serial.println("LED #7 is Off.\n");
  delay(1000);

  // Turn off outermost pair (LED1 and LED8)
  digitalWrite(LED1, LOW);
  Serial.println("LED #1 is Off.");
  digitalWrite(LED8, LOW);
  Serial.println("LED #8 is Off.\n");
  delay(1000);
}
