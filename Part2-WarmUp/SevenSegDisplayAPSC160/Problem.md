# Problem: Display "APSC160." on a 7-Segment Display

* **Recommended Time:** 10–15 min  
* **Topics:** Arduino Basics, Digital Output, Arrays, Functions, Control Flow

## Description
Write an Arduino program to display the word **"APSC160."** on a **single 7-segment display**. Each character should be displayed **one at a time**, in the correct sequence, with a short delay between characters to visualize the sequence clearly.  

Implement a function `toggleLEDs()` to update the states of the LEDs for each character.

**Constraints:**
* Only standard Arduino functions such as `digitalWrite()`, `pinMode()`, and `delay()` may be used.  
* Each character of "APSC160." must be represented using a hardcoded **8-element array** corresponding to the LEDs of the 7-segment display.  
* The display should cycle through the characters **indefinitely**, one character per second.  

## Input / Output
* **Input:** None (program runs automatically)  
* **Output:** The 7-segment display shows the characters of "APSC160." sequentially, one at a time.  

---

## Examples

**Behavior:**
1. The first character 'A' is displayed for 1 second.  
2. The second character 'P' is displayed for 1 second.  
3. The third character 'S' is displayed for 1 second.  
4. The fourth character 'C' is displayed for 1 second.  
5. The fifth character '1' is displayed for 1 second.  
6. The sixth character '6' is displayed for 1 second.  
7. The seventh character '0' is displayed for 1 second.  
8. The eighth character '.' is displayed for 1 second.
9. The sequence repeats indefinitely.

## Template

**TinkerCAD Link:** https://www.tinkercad.com/things/hRJdIiyuSUf-seven-segment-display?sharecode=xPwNpF4skPxzTIhzP3NwnY76VZYss_xdKJt-vF8t7s0
