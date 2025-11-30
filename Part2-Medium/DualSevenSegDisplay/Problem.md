# Problem: Dual 8-LED Display – Name and Student Number

* **Recommended Time:** 20-25 min  
* **Topics:** Arduino Basics, Digital Output, Arrays, Functions

## Description
Write an Arduino program to display your **name** and **student number** using two **8-LED displays**. Each display is capable of showing up to **8 characters**, with each character represented by 8 LEDs.

* Display your **name** (up to 8 characters) on the first display.  
* Display your **student number** (exactly 8 characters) on the second display.  
* The displays should be updated sequentially, with a **1-second delay** between each character.  
* Implement a function `toggleLEDs()` to update the states of both displays simultaneously.

**Constraints:**
* The LED pin wiring is already configured; no hardware setup is required.  
* Each display uses 8 pins for the LEDs.  
* Only standard Arduino functions such as `digitalWrite()`, `pinMode()`, and `delay()` may be used.  
* The program must loop continuously, cycling through all characters of both name and student number.

## Input / Output
* **Input:** None (characters to display are hardcoded in arrays).  
* **Output:** Two 8-LED displays showing your name and student number, updated one character at a time.

---

## Examples

**Behavior:**
1. First LED display shows the first character of your name.  
2. Second LED display shows the first character of your student number.  
3. After 1 second, both displays update to the next character.  
4. This continues until all 8 characters of the name and student number are displayed.  
5. Sequence repeats indefinitely.

**Example #1:**
Name: A>L>Y>K>H>A>N>.
Student Number: 8>9>4>4>4>1>3>7

**Example #2:**
Name: D>A>Y>L>E>N>.>.
Student Number: 4>9>2>7>9>2>7>6

## Template

**TinkerCAD Link:** https://www.tinkercad.com/things/44ayA5Sz6e0-dual-seven-segment-display?sharecode=05NPSkVI7FahYUo57CbjRLFR3kMrXJatXTzhn5H5nOk
