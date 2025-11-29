# Problem: Dual 8-LED Display with Pushbutton Control – Name and Student Number

* **Recommended Time:** 15–20 min  
* **Topics:** Arduino Basics, Digital Input & Output, Arrays, Functions, Control Flow

## Description
Write an Arduino program to display your **first name** and **student number** using two **8-LED displays**. Each display can show up to **8 characters**, with each character represented by 8 LEDs. The program should allow **interactive control** using two pushbuttons:

* **Pushbutton 1** (connected to A0): When pressed, the first display shows the first 8 characters of your **first name**. If your name is less than 8 characters, the remaining spots must be filled with decimal places.    
* **Pushbutton 2** (connected to A1): When pressed, the second display shows your **student number**.  

The displays should **switch immediately** when a button is pressed, and continue cycling through the characters of the selected string. Implement a function `toggleLEDs()` to update the states of both displays simultaneously.

**Constraints:**
* Pushbuttons are connected to **analog pins A0 and A1**.  
* The LED pin wiring is already configured; no additional hardware setup is required.  
* Each display uses 8 pins for the LEDs.  
* Only standard Arduino functions such as `digitalRead()`, `digitalWrite()`, `pinMode()`, and `delay()` may be used.  
* Characters of the name and student number must be hardcoded in arrays.  
* The program must continuously check for button presses and immediately switch the display when a button is pressed.

## Input / Output
* **Input:** Pushbutton presses (A0 and A1).  
* **Output:** Two 8-LED displays showing either the name or student number, updated one character at a time based on button input.

---

## Examples

**Behavior:**
1. No button pressed → displays remain in the previous state.  
2. Button 1 (A0) pressed → first display immediately shows the first character of the name; continues cycling through the name.  
3. Button 2 (A1) pressed → second display immediately shows the first character of the student number; continues cycling through the student number.  
4. Displays switch instantly whenever a button is pressed.  
5. The sequence repeats indefinitely while respecting button input.

**Example #1:**
Name: A>L>Y>K>H>A>N>.
Student Number: 8>9>4>4>4>1>3>7

**Example #2:**
Name: D>A>Y>L>E>N>.>.
Student Number: 4>9>2>7>9>2>7>6

## Template

**TinkerCAD Link:** 


