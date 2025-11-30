# Problem: Bidirectional LED Sequence with Variable Speed

**Recommended Time:** 20–25 min  
**Topics:** Digital Output, Arrays, Loops, Functions, Timing, Serial Communication

## Description

Write an Arduino program that controls **10 LEDs** connected to digital pins 4–13. The program must perform the following sequences repeatedly:

1. **Quick Forward Sequence:**  
   - LEDs turn on one by one from **LED #1 to LED #10**.  
   - Each LED stays **ON for 0.1 seconds** before moving to the next.  
   - Print the status of each LED to the Serial Monitor in the format: `LED #n is On.`  

2. **Quick Backward Sequence:**  
   - LEDs turn on one by one from **LED #10 to LED #1**.  
   - Each LED stays **ON for 0.1 seconds**.  
   - LEDs not currently active must be **OFF**.  
   - Print the status of the active LED to the Serial Monitor.  

3. **Slow Backward Sequence:**  
   - LEDs turn on one by one from **LED #10 to LED #1**.  
   - Each LED stays **ON for 1 second**.  
   - All other LEDs must be **OFF**.  
   - Print the status of the active LED to the Serial Monitor.  

The program should **loop indefinitely**, cycling through these sequences. Use a **function** for the backward sequences to structure the code modularly.

## Input / Output

**Input:**  
- No external input is required.

**Output:**  
- LEDs turning **ON/OFF** in the described sequences.  
- Serial Monitor prints the active LED in each step.

## Example Behavior

1. LEDs #1 → #10 turn ON **quickly** (0.1 s each).  
2. LEDs #10 → #1 turn ON **quickly** (0.1 s each).  
3. LEDs #10 → #1 turn ON **slowly** (1 s each).  
4. Sequence repeats indefinitely.

The program must follow similar behavior as indicated in this GIF:
![CPT2511291902-557x313 (online-video-cutter com)](https://github.com/user-attachments/assets/e7eb2ba4-056f-4c80-868e-84e49d456f9f)

## Template

**TinkerCAD Link**: https://www.tinkercad.com/things/4YEI4BSLE7D-led-blink-simulation-iii
