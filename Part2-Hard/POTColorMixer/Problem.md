# Problem: RGB LED Color Control Using Potentiometers

**Recommended Time:** 25–30 min  
**Topics:** Analog Input, PWM Output, Conditional Statements, Functions, Serial Communication

## Description

Write an Arduino program that controls an **RGB LED** using **three potentiometers** (one for each color channel: Red, Green, and Blue). The program should:

1. **Read potentiometer values** from analog pins A0, A1, and A2.  
2. **Map the potentiometer values** (0–1023) to PWM output values (0–255) using the formula:

`outputValue = sensorValue / 4`

where `sensorValue` is the analog reading from the potentiometer.

3. **Set the brightness** of the RGB LED based on the mapped PWM values.  
4. **Detect specific color combinations** based on maximum (255) or minimum (0) PWM values for each channel and print the corresponding color to the Serial Monitor:

- **Red:** Red = 255, Green = 0, Blue = 0  
- **Green:** Red = 0, Green = 255, Blue = 0  
- **Blue:** Red = 0, Green = 0, Blue = 255  
- **Purple:** Red = 255, Green = 0, Blue = 255  
- **Turquoise:** Red = 0, Green = 255, Blue = 255  
- **Yellow:** Red = 255, Green = 255, Blue = 0  
- **White:** Red = 255, Green = 255, Blue = 255  
- **Off:** Red = 0, Green = 0, Blue = 0  

5. Continuously update the LED color and print messages as the potentiometers are adjusted.

The program must implement the following functions:

- `toggleRed()`: Reads the Red potentiometer and sets the Red LED channel.  
- `toggleGreen()`: Reads the Green potentiometer and sets the Green LED channel.  
- `toggleBlue()`: Reads the Blue potentiometer and sets the Blue LED channel.  
- `toggleRGB(int outputValueRed, int outputValueGreen, int outputValueBlue)`: Determines the active color combination (including Purple, Turquoise, Yellow) and prints the color to the Serial Monitor.

## Input / Output

**Input:**  
- Three potentiometers connected to analog pins A0, A1, A2.  

**Output:**  
- RGB LED changes color based on potentiometer positions.  
- Serial Monitor prints the detected color name for maximum or minimum combinations, including Purple, Turquoise, and Yellow.

## Example Behavior

1. Red = 255, Green = 0, Blue = 0 → LED shows **Red**, Serial prints `"The RGB LED is Red."`  
2. Red = 0, Green = 255, Blue = 0 → LED shows **Green**, Serial prints `"The RGB LED is Green."`  
3. Red = 0, Green = 0, Blue = 255 → LED shows **Blue**, Serial prints `"The RGB LED is Blue."`  
4. Red = 255, Green = 0, Blue = 255 → LED shows **Purple**, Serial prints `"The RGB LED is Purple."`  
5. Red = 0, Green = 255, Blue = 255 → LED shows **Turquoise**, Serial prints `"The RGB LED is Turquoise."`  
6. Red = 255, Green = 255, Blue = 0 → LED shows **Yellow**, Serial prints `"The RGB LED is Yellow."`  
7. Red = 255, Green = 255, Blue = 255 → LED shows **White**, Serial prints `"The RGB LED is White."`  
8. Red = 0, Green = 0, Blue = 0 → LED is **Off**, Serial prints `"The RGB LED is Off."`  

The sequence continues dynamically as the potentiometers are adjusted.

## Template:

**TinkerCAD Link**: https://www.tinkercad.com/things/fgAwui1AOJB-rgb-led-amp-pot-control?sharecode=_XxM-uBuwdNJZTt_uyhhDj2E1G_oF1e-EMT59_H5z6A
