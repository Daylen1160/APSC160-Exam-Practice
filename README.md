# 💻 Welcome to the APSC 160 Final Exam Practice Problems Set! 💻

> **Disclaimer:** These questions are not officially endorsed by APSC 160's teaching team, they are just TAs' opinions.


## Overview
What's going on? This was made with Git, a software that is used by programmers to store code. You are currently on Github, the most commonly used platform that hosts code (like how YouTube hosts videos; Git and Github are not the same thing). You are currently looking at a repository (a folder with stuff in it).

**In a nutshell, The only important things you need to look at is `README.md` (what you're looking at now), `tips.md`, `C Programming`, and `Arduino Programming`.** The names are self explanatory, so have a look around!

This guide is meant to serve as an additional resource to studying for the APSC 160 Final. Preferably, work your way up the problems, from 'Warm Up/Easy' to 'Medium' and then 'Hard'. We also **strongly** recommend to check out `tips.md` too for additional advice! 

### For C Questions

You will have a question file, `problem.md`, and 3 C files:

- `template.c` Write your code here.
- `testing.c` Run this file. Change the `#include` at the top to run either `template.c` or `solution.c`, **do not change anything else**. If your program can get all the test cases here your solution is correct. 
- `solution.c` Do not change anything here. Answers are here.

### For Arduino Questions

You will also have a question file, `problem.md`. At the bottom, there will be a link to open the file and create a copy on TinkerCAD. 
- `solution.c` Do not change anything here. Answers are here. There's obviously no autograder since it's in TinkerCAD, you need to determine if your solution functions as expected as in the instructions.


## How to Access This Repository

<ins> For the C questions, There are two different ways: </ins>

### 1. OnlineGDB

Copy and paste the template and solution files into onlineGDB. Make sure to use the *new file* button to create 3 separate files (and more if it's a file I/O question). **Make sure to put `testing.c` in the main file.** You can do this copy and paste method on other IDE's too if you are too lazy to do it the Git way below.

### 2. Using Git

> Note: Only Windows (10/11) OS does not have Git pre-installed

> I would recommend doing this if you are interested in CPEN, ELEC, or BMEG as you will inevitably be using Git in the future for classes!

For those who want to use their own IDE (VSCode, VS, Codeblocks, etc), click *Code* and *Copy the HTTPS link*. Navigate to your directory of choice. Then in *Terminal* or *Command Prompt*.   Clone the repository using the following:
``` bash
git clone [THE LINK YOU JUST COPIED]
```

Now open the folder in your IDE and run from there!

<br> </br>
#### What happens if changes are made by us (and hopefully announced on Piazza)?

Open your terminal in the `APSC-160-Practice` folder and run:
``` bash
git pull origin main
```
---
<ins> For Arduino questions: </ins>  

In the `problem.md` file, there is a template to TinkerCAD
## Topics Covered

- **C Programming**
    - Fundamentals
    - User I/O [PROBLEMS HERE DO NOT COVER]
    - File I/O
    - Control
    - Functions
    - Arrays
    - Strings
    - Random Numbers
- **Arduino Programming**
    - Digital I/O
    - Analog I/O
    - 7-Segment Display  
    - Random Numbers
    - Timing
    - Advanced Timing  

> Note that the `C Programming` repository/folder includes Part 1 and Part 2 C content


## Authors

| Name | Year | Major | Email |
|:---:|:---:|:---:|:---:|
| Daylen Chun | 2nd | Computer Engineering | dchun924@student.ubc.ca |
| Aly Khan Nuruddin | 4th | Biomedical Engineering | alykhan5@student.ubc.ca |



## Inquiries

If you find any mistakes/problems/suggestions in `C Programming` or issues with the repository, email dchun924@student.ubc.ca

If you find any mistakes/problems/suggestions in `Arduino Programming`, email alykhan5@student.ubc.ca

If you want additional tips/insights or anything else, email either/both of us!

---

### Future Updates <sub> (hopefully) </sub>
- Make user I/O problems
- Get random/string problems from Aly's guide working
