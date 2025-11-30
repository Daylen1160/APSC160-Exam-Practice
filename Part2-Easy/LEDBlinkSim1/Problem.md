# Problem: Forward and Backward LED Blink Sequence

* **Recommended Time:** 15–20 min  
* **Topics:** Arduino Basics, Digital Output, Arrays, Functions, Control Flow

## Description
Write an Arduino program to control **6 LEDs** connected to digital pins. The program should implement a **forward and backward LED sequence**:

* **Forward Sequence:** Turn on each LED **one at a time** from the first to the last, while turning all other LEDs off.  
* **Backward Sequence:** Turn on each LED **one at a time** from the last to the first, while turning all other LEDs off.  

Each LED should remain **ON for 1 second** before moving to the next LED in the sequence. After completing the forward and backward sequences, the program should repeat indefinitely.  

Use separate functions `forwardSeq()` and `backwardSeq()` to implement the sequences. Optionally, print messages to the Serial Monitor to indicate which LED is ON.

**Constraints:**
* Only standard Arduino functions such as `digitalWrite()`, `pinMode()`, `delay()`, and `Serial.print()` may be used.  
* Use arrays to manage LED pins.  
* Ensure only **one LED is ON at a time**.  
* The sequence repeats indefinitely.

## Input / Output
* **Input:** None (program runs automatically)  
* **Output:** LEDs turn on one at a time in forward and backward sequences; optionally, print the LED number to the Serial Monitor.

---

## Example

**Behavior:**
1. Forward sequence: LED 1 → LED 2 → LED 3 → LED 4 → LED 5 → LED 6, each for 1 second.  
2. Backward sequence: LED 6 → LED 5 → LED 4 → LED 3 → LED 2 → LED 1, each for 1 second.  
3. Repeat indefinitely.  

**Serial Monitor Output (optional):**

LED 1 is ON.
LED 2 is ON.
LED 3 is ON.
...
LED 6 is ON.

LED 6 is ON.
LED 5 is ON.
LED 4 is ON.
...
LED 1 is ON.

## Template

**TinkerCAD Link:** https://www.tinkercad.com/things/7wXzC4COsmm-led-blink-sequence?sharecode=8d1VRmtBS1S3V9ZXccKaw01fvGO65AxMoaELec8TNvU
