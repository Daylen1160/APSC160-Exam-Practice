# 🟢 Random Digit String Analysis

**Recommended Time:** 10 - 15 min

**Topics:** Branching, Loops, Functions, 1D Array, Files I/O, String, User I/O

## Description
Write a C program that performs the following steps:
1. Generate a random string of exactly 20 digits (characters '0' through '9'). You must use C's random number generation facilities, ensuring you properly seed the generator.
2. Display the generated sequence to the user.
3. Prompt the user to enter a single digit character they want to search for.
4. Count how many times the user's digit appears within the generated random string.
5. Output the final count in a clear sentence.

NOTE: Ignore the input.txt and output.txt produced

## Examples
```text
Input: 10395820495720394855 (Generated)
Digit: 9
Output: Digit 9 appears 3 times.
```
```text
Input: 22718366901235489762 (Generated)
Digit: 2
Output: Digit 2 appears 5 times.
```
```text
Input: 31415926535897932384 (Generated)
Digit: 0
Output: Digit 0 appears 0 times.
```

## Hint:

To convert a character digit (e.g., '3') to its integer value (3), you can add or subtract the character '0' from it. For example:
```c
char digitChar = '3';
int digitValue = digitChar - '0';
```

