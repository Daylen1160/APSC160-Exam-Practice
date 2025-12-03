# 🔴🔴🔴 EXTRA-HARD Problem: Arduino Simon Game Implementation

**Recommended Time:** 75-90 minutes  
**Topics:** Arrays, Functions, Digital Input/Output, Random Numbers, Control Flow, Loops

## Description

You are to implement the Simon game in C using the Arduino simulator. The following figure shows a sample implementation of the game:

![CPT2511291902-557x313 (online-video-cutter com)](https://github.com/user-attachments/assets/98c7b8c5-fe68-4316-bedc-e5a15a08a344)

When turned on, the LEDs from 0 to 3 are of the following colours: Green, Red, Yellow, and Blue, respectively. LED0 is associated with PushButton0, LED1 with PushButton1, and so forth.

**Note:** This question was a previous lab for this course. If you can ace this problem, chances are you will fare pretty well on the final exam :)

### Game Overview

Simon is a simple memory skills electronic game that goes back to the early era of electronic games.

A sequence of colors are shown to the player. The player should memorize those and reproduce the same sequence by pushing the corresponding switches.
The displayed sequence begins with a single colour (displayed on the corresponding LED by blinking once).
If the player follows successfully (i.e. remembers the correct colour and pushes the corresponding button correctly), another randomly chosen colour is added to the end of the sequence each time and this new sequence is displayed (displayed on the corresponding LEDs one after the other by blinking each once). So the sequence becomes longer each time (and so harder to memorize).
The game ends if the player makes a mistake, or if the player wins (following the pattern all the way up to the (pre-set) maximum length of the sequence.) Your program though should start a new game right after that, until the use quits.
Have a look at **http://en.wikipedia.org/wiki/Simon_(game)** for more info.

We want to develop a program that implements a simple version of the game.

- There are **4** color LEDs.
- There are **4** corresponding switches. Note that these switches are push-button switches (like the keys on a keyboard). So you need to implement reading from them.
- The maximum sequence length is fixed at 5 (although it could be easily modified to be longer).

<img width="805" height="487" alt="image" src="https://github.com/user-attachments/assets/fecae92f-b940-4286-b611-85fec982b939" />


**Example:** Let’s say the computer chooses a sequence of
(red, red, blue, yellow, green)

First the red LED is turned on (flashed).
If the player presses the red button, then the sequence (red, red) is displayed (otherwise, the player has made a mistake and a new game is started.)
If the player presses (red, red), then the sequence (red, red, blue) is displayed (otherwise, the player has made a mistake and a new game is started.)
…
If the player presses (red, red, blue, yellow, green), s/he has won (otherwise lost) and a new game is started.

### Writing the Program

Now that we know what we expect from the program (clear problem statement), we should start implementing it.

We first devise an algorithm for implementing this program.
Then we write the primary structure of the program based on the Arduino framework.
Then we implement the required functions:
a function to implement the functionality of the Simon game,
a function to generate the required random sequence,
and any other required functions.
Finally (and periodically), we debug and test the program

### Algorithm (Suggested)

One possible algorithm for implementing the simple Simon game is:

- generate a random sequence of 5 numbers between 0 and 3 (inclusive, representing the colours, sequence length is 5)
- start with 1 LED (N=1)
- continue while the user wants to play
  - turn on (flash) the first N LEDs in the sequence one by one
  - read the user's input (i.e. read the buttons)
  - if the user gets it correctly the user wins (flash the green LED three times to indicate a win)
   - start a new game
   - increment N
   - if N equals to the sequence length
  - else
   - the user loses (flash the red LED three times to indicate a loss)
   - start a new game

Use practical and reasonable timing (not too long nor too short): allow some short time before the game starts/restarts (allowing the player to get ready), use practical LED flashing times, the same goes with the interval between displaying each colour of the random sequence to the player, ...

You may want to consider implementing a time-out feature, so that if the user does not press a button after a certain time, they lose the game.

### Programming Challenges

1) Reading from push-button switches
In this program, we are reading from push-button switches (covered in examples/videos previously).

Note that when you change the state of a toggle switch (like in Lab 7), it keeps its state until you change it again. So you could just call digitalRead one time (some time after this change of state) and know its new status. For the push-button, when you press it, its state changes to ON, but as soon as you release it, it goes back to its default state (OFF).

You simply need to consider this procedure, when you implement reading from the push buttons: a) your program must sense that the push button is pressed (i.e. it is on now) and b) it should wait until it is released (back to off again) -> that constitutes one click of that push button.

- Your program still has to be responsive if the user pushes a button while a LED is lit (ON).
- The push button must be responsive to a brief click as well as a longer press.

2) Generating Random Sequences (Numbers)
The sequence should be different at each instance of the game, and so the program should generate random sequences. We need to write a function that generates the sequence of random numbers for our game. How do we generate random integers between 0 and 3?

The Arduino reference library provides the function:

random(max);

random(min,max);

Returns a pseudo-random integer in the range 0 to max (0 included in range, max not included), or in the range min to max (min included in range, max not included).
The pseudo-random integers are equally likely to occur (statistically speaking, they have a uniform distribution.)
To initialize (seed) the random number generator, we use the following call to the function randomSeed()

randomSeed( seed);
As seed you can use a reading from an analog input that is likely to be random at the moment of reading (e.g. a floating analog input)
This function call uses a random voltage value (converted to an integer from 0 to 1023) as the seed for the random number generator.
Assuming we run the program at different times, different sequences of pseudo-random numbers will be generated.

Always seed the random number generator before using it! An example will be provided in class.

## Template

**TinkerCAD Link:** https://www.tinkercad.com/things/bSM7T86kmvk-simon-game?sharecode=czHltkuWIeBbPtBeEcbnI9NKsiiW7DLpAQgcdPgTsoU
