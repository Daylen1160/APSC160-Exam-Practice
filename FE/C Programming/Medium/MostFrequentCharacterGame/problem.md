# 🟡 Most Frequent Character Game

**Recommended Time:** 25 - 30 min

**Topics:** Branching, Loops, Functions, 1D Array, Files I/O, String, User I/O

## Description
Write a C program that executes a simple guessing game:
1. Generate a random string of 20 lowercase letters (a-z).
2. Display the generated 20-letter sequence to the user.
3. Analyze the string to determine the maximum frequency and the character(s) that achieved that frequency.
4. Start a guessing loop: Repeatedly prompt the user to guess the most frequent character and its exact count. The loop should continue until the user correctly guesses both the character and the frequency.
5. If the user guesses both correctly, display a "You Win!" message and end the program.

Note: In case of a tie, any of the correct letters provided would be sufficient.

## Examples
```text
Sequence: kllkjhgfdrtkuiolkjhh
Output:
Most frequent character: k
Frequency: 4
```
```text
Input: abcdegghhijjkklmmopprr
Output:
Most frequent character: g,h,j,k,m,p,r
Frequency: 2
```
```text
Input: zzzzaaabbbccddddeeeeef
Output:
Most frequent character: z, e
Frequency: 5
```


