# 🟡 Potentiometer-Controlled LED Sequence

**Recommended Time:** 20–25 min  
**Topics:** Analog Input, Digital Output, Control Flow, Variables, Functions, Timing

## Description

Write an Arduino program that uses a **potentiometer** to control the **speed of an LED sequence**. The program should:

- Control an array of **6 LEDs** connected to digital pins.  
- Light the LEDs in a **forward sequence** (first to last) and then in a **backward sequence** (last to first).  
- Use a **potentiometer** connected to an analog pin to adjust the **speed of the LED transitions**.  

The program must implement the following functions:

- `forwardSeq()`: Lights the LEDs from first to last.  
- `backwardSeq()`: Lights the LEDs from last to first.  
- `lightSpeed()`: Reads the potentiometer value, maps it to a delay range, and delays accordingly.

### Analog to Potentiometer Mapping Formula

To convert the potentiometer value (0–1023) to a delay in milliseconds:
`delayTime = ((sensorValue / 1023.0) * 900) + 100`

- `sensorValue`: analog reading from potentiometer (0–1023)  
- `delayTime`: resulting LED delay in milliseconds (100–1000 ms)

## Input / Output

**Input:**  
- One potentiometer connected to an analog input pin.

**Output:**  
- LED sequence moving forward and backward.  
- LED speed varies based on potentiometer position.

## Example Behavior

1. Potentiometer at minimum → LED sequence moves slowly.  
2. Potentiometer at maximum → LED sequence moves quickly.  
3. LEDs light in order 1→2→3→4→5→6 and then reverse 6→5→4→3→2→1.  

The sequence continues indefinitely, with speed dynamically controlled by the potentiometer.

## Template

**TinkerCAD Link**: https://www.tinkercad.com/things/c0o8fjyzfV7-led-blink-pot-simulation?sharecode=Gh4GnqMbEOhvu6-lvebR54Xz6UUdDKYnY9YNjx8V1cg
