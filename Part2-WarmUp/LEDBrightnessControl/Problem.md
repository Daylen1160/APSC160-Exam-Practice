# Problem: LED Brightness Control with Pushbuttons

* **Recommended Time:** 5–10 min  
* **Topics:** Arduino Basics, Digital Input, PWM Output, Control Flow

## Description
Write an Arduino program that adjusts the brightness of an LED using two pushbuttons. The program should meet the following requirements:

* The LED brightness is initially set to **128** (midway of the PWM range 0–255).  
* Pressing **Button 1** decreases the LED brightness by **1**.  
* Pressing **Button 2** increases the LED brightness by **1**.  
* The LED brightness must always remain within the valid PWM range of **0 to 255**.  
* The LED should be updated smoothly using `analogWrite()`.

Each loop iteration should:
* Read the state of both pushbuttons  
* Adjust brightness according to button presses  
* Constrain the brightness value to stay within 0–255  
* Apply the brightness to the LED

Helper functions such as `increaseBrightness()` and `decreaseBrightness()` are optional.

**Constraints:**
* The circuit is already wired with:
  - Two momentary pushbuttons  
  - One LED connected to a PWM-capable pin  
* The brightness changes **one step at a time** per loop iteration

## Input / Output
* **Input:** Pushbutton states (pressed or not pressed).  
* **Output:** LED brightness level (0–255), controlled via PWM.

---

## Examples

**Behavior:**
1. LED starts at brightness 128.  
2. Holding Button 1 → LED brightness decreases gradually by 1 per loop iteration.  
3. Holding Button 2 → LED brightness increases gradually by 1 per loop iteration.  
4. Releasing both buttons → LED maintains its current brightness.  
5. Brightness remains capped at 0 (min) and 255 (max).

## Template

**TinkerCAD Link:** https://www.tinkercad.com/things/5obvVYgey2f-led-brightness-control?sharecode=ReiuaLIBHQsMIbGj2L6XX9Csg_UQ_R5ig14BzFDeGXM
