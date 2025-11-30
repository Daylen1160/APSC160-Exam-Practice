// Number of buttons and LEDs in the game
#define NUM_COMPONENTS 4

// Maximum length of the Simon sequence
#define MAX_SEQUENCE_LENGTH 5

// Time constants
#define ONE_SEC 1000

// LED pins for win/loss indicators
#define LED_WIN 9
#define LED_LOSS 8

// Arrays holding pin numbers for game buttons and corresponding LEDs
const int simonButtons[NUM_COMPONENTS] = {7, 6, 5, 4};
const int simonLEDs[NUM_COMPONENTS] = {13, 12, 11, 10};

// Function prototypes
void generateSequence(int randNumber[]);  // Generates a random Simon sequence
void blinkSequence(int sequenceLength, int randNumber[], const int simonLEDs[]); // Blinks LEDs according to sequence
void verifySequence(int sequenceLength, int randNumber[], int buttonState[], const int simonButtons[]); // Checks user input against sequence

void simonLoss();  // Handles losing the game
void simonWin();   // Handles winning the game
void simonNew(const int simonLEDs[]); // Resets LEDs and starts a new game

// ----------------------------
// Configures pins and initializes serial communication
// ----------------------------
void setup()
{
  // Configure Simon buttons as INPUT
  for(int counter = 0; counter < NUM_COMPONENTS; counter++)
  {
    pinMode(simonButtons[counter], INPUT);
    pinMode(simonLEDs[counter], OUTPUT); // Configure corresponding LEDs as OUTPUT
  }

  // Configure win/loss LEDs as OUTPUT
  pinMode(LED_WIN, OUTPUT);
  pinMode(LED_LOSS, OUTPUT);

  // Initialize random number generator using analog noise
  randomSeed(analogRead(0));

  // Initialize Serial communication for debugging
  Serial.begin(9600);
}

// ----------------------------
// Runs the Simon game sequence repeatedly
// ----------------------------
void loop()
{
  int sequenceLength = 0;                 // Tracks current sequence length
  int buttonState[NUM_COMPONENTS];        // Stores button states
  int randNumber[MAX_SEQUENCE_LENGTH];    // Stores random Simon sequence

  // Generate a new random sequence
  generateSequence(randNumber);

  // Loop through increasing sequence lengths up to the max
  while(sequenceLength <= MAX_SEQUENCE_LENGTH)
  {
    // Blink LEDs according to current sequence
    blinkSequence(sequenceLength, randNumber, simonLEDs);
    delay(ONE_SEC);

    // Check user input for correctness
    verifySequence(sequenceLength, randNumber, buttonState, simonButtons);

    sequenceLength++;
  }

  // Reset the game with LED flash animation
  simonNew(simonLEDs);
  delay(0.1 * ONE_SEC);
}

// ----------------------------
// Generates a random sequence of LED indices for Simon game
// ----------------------------
void generateSequence(int randNumber[])
{
  for(int counter = 0; counter < MAX_SEQUENCE_LENGTH; counter++)
  {
    randNumber[counter] = random(NUM_COMPONENTS); // Random index between 0 and NUM_COMPONENTS-1
  }
}

// ----------------------------
// Blinks LEDs according to the current sequence
// ----------------------------
void blinkSequence(int sequenceLength, int randNumber[], const int simonLEDs[])
{
  for(int counter = 0; counter < sequenceLength; counter++)
  {
    // Turn LED on
    digitalWrite(simonLEDs[randNumber[counter]], HIGH);
    delay(ONE_SEC);

    // Turn LED off
    digitalWrite(simonLEDs[randNumber[counter]], LOW);
    delay(ONE_SEC);
  }
}

// ----------------------------
// Reads button inputs and checks against the Simon sequence
// ----------------------------
void verifySequence(int sequenceLength, int randNumber[], int buttonState[], const int simonButtons[])
{
  int sequence = 0;

  // Loop through each step in the sequence
  while(sequence < sequenceLength)
  {
    // Read all button states
    for(int counter = 0; counter < NUM_COMPONENTS; counter++)
    {
      buttonState[counter] = digitalRead(simonButtons[counter]);
    }

    // Compare pressed button with expected sequence
    for(int counter = 0; counter < NUM_COMPONENTS; counter++)
    {
      if(randNumber[sequence] == counter)
      {
        if(buttonState[randNumber[sequence]] == HIGH);
        {
          delay(ONE_SEC);  // Wait for user input to settle
          counter++;
        }
      }
      else
      {
        if(buttonState[counter] == HIGH);
        {
          simonLoss(); // Incorrect button pressed
        }
      }
    }
  }
}

// ----------------------------
// Flashes loss LED and prints message
// ----------------------------
void simonLoss()
{
  int numBlinks = 5;

  Serial.print("You lost the game. Try again next time!");

  for(int counter = 0; counter < numBlinks; counter++)
  {
    digitalWrite(LED_LOSS, HIGH);
    delay(0.5 * ONE_SEC);
    digitalWrite(LED_LOSS, LOW);
    delay(0.5 * ONE_SEC);
  }

  delay(ONE_SEC);

  // Reset the game LEDs
  simonNew(simonLEDs);
}

// ----------------------------
// Flashes win LED and prints message
// ----------------------------
void simonWin()
{
  int numBlinks = 5;

  Serial.print("You won the game. Congratulations!");

  for(int counter = 0; counter < numBlinks; counter++)
  {
    digitalWrite(LED_WIN, HIGH);
    delay(0.5 * ONE_SEC);
    digitalWrite(LED_WIN, LOW);
    delay(0.5 * ONE_SEC);
  }
  delay(ONE_SEC);

  // Reset the game LEDs
  simonNew(simonLEDs);
}

// ----------------------------
// Turns all LEDs on and off to signal a new game start
// ----------------------------
void simonNew(const int simonLEDs[])
{
  // Turn all game LEDs ON
  for(int counter = 0; counter < NUM_COMPONENTS; counter++)
  {
    digitalWrite(simonLEDs[counter], HIGH);
  }

  digitalWrite(LED_LOSS, HIGH);
  digitalWrite(LED_WIN, HIGH);

  delay(2 * ONE_SEC);

  // Turn all game LEDs OFF
  for(int counter = 0; counter < NUM_COMPONENTS; counter++)
  {
    digitalWrite(simonLEDs[counter], LOW);
  }

  digitalWrite(LED_LOSS, LOW);
  digitalWrite(LED_WIN, LOW);

  delay(2 * ONE_SEC);
}
