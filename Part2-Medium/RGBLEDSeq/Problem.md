# Problem: Random RGB LED Pattern Generator

* **Recommended Time:** 20-25 min  
* **Topics:** Arduino Basics, Digital & Analog Output, Functions, Random Numbers, Control Flow

## Description
Write an Arduino program to control a **single RGB LED** connected to three PWM pins. The program should generate a **random sequence of colors** (Red, Blue, Green) for the RGB LED and display each color for 1 second. Additionally, the program should print the active color to the **Serial Monitor**.  

Implement the following functions:

* `generateRandom(int randomLED[NUM_LEDS])` – Generates a random sequence of LEDs to light up.  
* `toggleRED()` – Turns on the red component of the RGB LED and turns off blue and green.  
* `toggleBLUE()` – Turns on the blue component and turns off red and green.  
* `toggleGREEN()` – Turns on the green component and turns off red and blue.  

**Constraints:**
* Use only standard Arduino functions such as `analogWrite()`, `pinMode()`, and `Serial.println()`.  
* The RGB LED is connected to **three PWM pins - 11, 10, 9**  for **red, blue, green** respectively.
* The sequence should repeat indefinitely, generating a new random pattern each loop.  
* Print the currently active color to the **Serial Monitor**.  

## Input / Output
* **Input:** None (the program generates random LED colors automatically).  
* **Output:** RGB LED displays a random color each second, and the active color is printed to the Serial Monitor.  

---

## Example

**Behavior:**
1. The program generates a random sequence: RED → GREEN → BLUE.  
2. The RGB LED lights up RED for 1 second and prints `"The RED LED is On."`.  
3. The RGB LED lights up GREEN for 1 second and prints `"The GREEN LED is On."`.  
4. The RGB LED lights up BLUE for 1 second and prints `"The BLUE LED is On."`.  
5. The sequence repeats indefinitely with a new random order each cycle.

## Template

**TinkerCAD:** https://www.tinkercad.com/things/dGQFMcObD6O-rgb-led-sequence
