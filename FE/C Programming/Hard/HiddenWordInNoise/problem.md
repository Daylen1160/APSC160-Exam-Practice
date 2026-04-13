# 🔴 Hidden Word in Noise

**Recommended Time:** 30 - 40 min

**Topics:** Branching, Loops, User I/O, Functions, 1D Array, Files I/O, String, Random

## Description
Write a C program that embeds a hidden word within a long string sequence of random lowercase letters.
The user must guess the hidden word.
1. **Preparation**:
    - Define a list of short words (e.g., "tree", "cat"). Randomly select a Target Word.
2. **String Assembly**: The total length of the sequence is exactly 30 characters long, by combining the target word with required amount of noise. You must:
    - Calculate the amount of random noise needed (30 - Target Word Length).
    - Randomly select a starting insertion index for the Target Word.
    - Assemble the sequence with the a mix of noise/random lowercase characters (before and after the insertion point) and the Target Word.
3. **Game Loop**: Display the sequence.Repeatedly prompt the user until they correctly guess the Target Word. Once the user guesses, display they guessed the word.

## ASCII Table
![ASCII_table](../../../../img/ascii.gif "ASCII_table")

## Examples
```text
xfqpjrtaqgbluetreerwqmnvzpsikl

blue
rats
donkey
tree
You guessed the word correctly!
```

```text
prkbaacatdfuvmqlnzxweqroiutmbc
lmao
zoinks
dog
cat
You guessed the word correctly!
```
```text
mznxqowlkbuterflyprqvmaopstlxq
fly
You guessed the word correctly!
```


