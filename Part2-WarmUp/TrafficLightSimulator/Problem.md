# Problem: Traffic Light Simulator

* **Recommended Time:** 5-10 min
* **Topics:** Arduino Basics, Digital Output, Control Flow

## Description
Write an Arduino program that controls a **pre-wired traffic light circuit** with three LEDs: green, yellow, and red. Your program must turn on each light for a specific duration to simulate a real traffic-light cycle.

The required timing sequence is:
* Green for **15 seconds**
* Yellow for **3 seconds**
* Red for **15 seconds**

Only one LED should be on at a time. Helper functions (such as `green_light()`, `yellow_light()`, `red_light()`) are optional.

**Constraints:**
* Circuit wiring is already completed; **no hardware setup is required**.
* The program must repeat the traffic-light cycle indefinitely.
* Use `digitalWrite()` and `delay()` to control the LEDs.

## Input / Output
* **Input:** None (the program runs continuously on the Arduino).
* **Output:** LED sequence: Green → Yellow → Red → repeat.

---

## Example

**Behavior:**
1. Green LED turns ON for 15 seconds (yellow and red OFF).
2. Yellow LED turns ON for 3 seconds (green and red OFF).
3. Red LED turns ON for 15 seconds (green and yellow OFF).
4. Cycle repeats forever.

---

## Template

**TinkerCAD Link**: https://www.tinkercad.com/things/2cSuYRrw5Z7-traffic-light-simulator?sharecode=E1lhmSC1Km7nymvrdpzd58qdi9EA11b_LZiTo2bf4Vg
