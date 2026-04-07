# 🟡 Most Frequent Character Game

**Recommended Time:** 25 - 30 min

**Topics:** Loops, Characters, Random Numbers

## Description
Write a C program that executes a simple guessing game:
1. Generate a random string of 20 lowercase letters (a-z).
2. Display the generated 20-letter sequence to the user.
3. Analyze the string to determine the maximum frequency and the character(s) that achieved that frequency.
4. Start a guessing loop: Repeatedly prompt the user to guess the most frequent character and its exact count. The loop should continue until the user correctly guesses both the character and the frequency.
5. If the user guesses both correctly, display a "You Win!" message and end the program.

Note: In case of a tie, any of the correct letters provided would be sufficient.

## ASCII Table
![ASCII_table](../../../../img/ascii.gif "ASCII_table")

## Examples
```text
Sequence: kllkjhgfdrtkuiolkjhh
User guess: k 4
Output: You Win!
```
```text
Sequence: abcdegghhijjkklmmopprr
User guess: a 2
Output: Incorrect guess. Try again.
User guess: g 2
Output: You Win!
```
```text
Sequence: zzzzaaabbbccddddeeeeef
User guess: e 5
Output: You Win!

Explanation: Both 'z' and 'e' are tied for most frequent at 5,
so either letter with frequency 5 is accepted.
```
