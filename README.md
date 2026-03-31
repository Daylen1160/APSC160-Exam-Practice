# 💻 Welcome to the APSC 160 Exam Practice Problems Set! 💻

> **Disclaimer:** These questions are not officially endorsed by APSC 160's teaching team, they are just TAs' opinions.

## Overview
What's going on? This was made with Git, a software that is used by programmers to store code. You are currently on Github, the most commonly used platform that hosts code (like how YouTube hosts videos; Git and Github are not the same thing). You are currently looking at a repository (a folder with stuff in it).

**In a nutshell, The only important things you need to look at is `README.md` (what you're looking at now), `tips.md`, `debugging.md`, `MT2`, and `FE` where the `FE` has `C Programming`, and `Arduino Programming`.** The names are self explanatory, so have a look around!

This guide is meant to serve as an additional resource to studying for APSC 160 Exams. Preferably, work your way up the problems, from _Warm Up/Easy_ to _Medium_ and then _Hard_. We also **strongly** recommend to check out `tips.md` and `debugging.md` too for additional advice and insight! 

Each folder contains only content up to that point that is relevant to that. So for ___ you should study:
- MT2: MT2
- FE: MT2, & FE

### For C Questions

You will have a question file, `problem.md`, and 3 C files:

- `template.h` Write your code here.
- `testing.c` Run this file. Change the `#include` at the top to run either your template or our solution, **do not change anything else**. If your program can get all the test cases here your solution is correct. 
- `solution.h` Do not change anything here. Answers are here.

### For Arduino Questions

You will also have a question file, `problem.md`. At the bottom, there will be a link to open the file and create a copy on TinkerCAD. 
- `solution.c` Do not change anything here. Answers are here. There's obviously no autograder since it's in TinkerCAD, you need to determine if your solution functions as expected as in the instructions.


## How to Access This Repository

<ins> For the C questions, There are three different ways: </ins>

### 1. OnlineGDB

Copy and paste the template and solution files into onlineGDB. Make sure to use the *new file* button to create 3 separate files (and more if it's a file I/O question). **Make sure to put `testing.c` in the main file.** You can do this copy and paste method on other IDE's too if you are too lazy to do it the Git way below. **You will need to rename the template and solution file to `template.h` and `solution.h`, otherwise it will not run.**

![onlineGDB Demo](img/onlinegdb_demo.gif "onlineGDB Demo")

### 2. Using Git

> Note: Only Windows (10/11) OS does not have Git pre-installed: https://github.com/git-guides/install-git
> To check, in *Terminal* or *Command Prompt*, type:
``` bash
git --version
```

> I would recommend doing this if you are interested in CPEN, ELEC, or BMEG as you will inevitably be using Git in the future for classes!

For those who want to use their own IDE (VSCode, VS, Codeblocks, etc), click *Code* and *Copy the HTTPS link*. Navigate to your directory of choice. Then open *Terminal* or *Command Prompt* or *Git Bash*. Clone the repository using the following:

``` bash
git clone [THE LINK YOU JUST COPIED]
```

Now open the folder in your IDE and run from there!

> I use Visual Studio Code (VSCode) but feel free to use whatever IDE you'd like! https://code.visualstudio.com/docs/languages/cpp (C/C++ both work the same)

![Git Demo](img/git_demo.gif "Git Demo")

#### What happens if changes are made by us (and hopefully announced on Piazza)?

Open your terminal and navigate to the `APSC160-Exam-Practice-2025` folder and run:
``` bash
git pull origin main
```


### 3. Copy and Pasting/Downloading the Directory into your IDE

I don't recommend this method to be fair. As I'd choose to be simplistic with OnlineGDB or up to industry standard with Git.

To do it through downloading, click *Code* then *Download ZIP*. Then open the folder in your IDE.

You can also just create the `template.h`, `solution.h`, and `testing.c` files yourself, and then copy and paste from this website. (like what I did in OnlineGDB)


---
<ins> For Arduino questions: </ins>  

In the `problem.md` file, there is a template to TinkerCAD. Complete the program there, and make sure it is set to private.

## Topics Covered

### MT2:
- **C Programming**
    - Fundamentals
    - ~~User I/O~~ [NO PROBLEMS]
    - File I/O
    - Control
    - Functions
    - Arrays (1D & 2D)

### FE:
- **C Programming**
    - All of MT2 Content
    - Strings
    - Random Numbers
- **Arduino Programming**
    - Digital I/O
    - Analog I/O
    - 7-Segment Display  
    - Random Numbers
    - Timing
    - Advanced Timing  

## Authors

| Name | Year | Major | Email | Currently TAing? |
|:---:|:---:|:---:|:---:| :---:
| Daylen Chun | 2nd | CPEN | dchun924@student.ubc.ca | ✅
| Aly Khan Nuruddin | Graduated! 🥳 | BMEG| alykhan5@student.ubc.ca | ❌

>Mind starring the repository if you enjoyed it? :)

## Inquiries

If you find any mistakes/problems/suggestions in `C Programming` or `Arduino Programming` or issues with the repository/git/getting things running, email dchun924@student.ubc.ca

Feel free to use Piazza to post questions related to solving the problems. Bonus points will be awarded to posting new, unique, innovative solutions to the problems.

If you want additional tips/insights or anything else, email dchun924@student.ubc.ca

---

### Future Updates <sub> (hopefully) </sub>

Updates to the repository can be found at `CHANGELOG.md`. Be sure to check there every now and then so you know whether to refresh the repository or not. I'll announce a Piazza statement if it's important too.

- Create MT1 Problems
- Make user I/O problems
- Move to PL
- Add comments to solutions (maybe?)
