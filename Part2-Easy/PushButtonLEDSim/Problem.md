# Problem: Alternating Blue–Green LED Blink Counter

**Recommended Time:** 15–20 min  
**Topics:** Digital Input, Digital Output, Variables, Functions, Control Flow

## Description

Write an Arduino program that uses **one pushbutton** to control **two LEDs** (Blue and Green).  
Each time the pushbutton is pressed:

- The program counts the total number of button presses.  
- If the number of presses is **odd**, the **Blue LED** blinks *numPress* times.  
- If the number of presses is **even**, the **Green LED** blinks *numPress* times.  

When the button is **not pressed**, both LEDs must remain **OFF**.

The program must implement the following functions:

- `toggleLED(int buttonState)`  
  Determines whether a press has occurred, increments the counter, and chooses which LED to blink.

- `blinkBlue(int numPress)`  
  Blinks the blue LED *numPress* times.

- `blinkGreen(int numPress)`  
  Blinks the green LED *numPress* times.

## Input / Output

**Input:**  
- One pushbutton connected to a digital input pin.

**Output:**  
- Blue or Green LED blinks depending on the press count.  
- Serial Monitor prints which LED blinked during each cycle.

## Example Behavior

1. First press → **1 press (odd)** → Blue LED blinks **1** time.  
2. Second press → **2 presses (even)** → Green LED blinks **2** times.  
3. Third press → **3 presses (odd)** → Blue LED blinks **3** times.  
4. Fourth press → **4 presses (even)** → Green LED blinks **4** times.

The sequence continues indefinitely.

---

# Template

**TinkerCAD Link:** https://www.tinkercad.com/things/gxzP7iPxu5k-push-button-led-simulation?sharecode=3bmBjRy5zD66DEc7tWmFReYo9Xs4nYN6AyiVRoy7_lk
