# 🔴 Hidden Word in Noise

**Recommended Time:** 30 - 40 min

**Topics:** Branching, Loops, User I/O, Functions, 1D Array, Files I/O, String, Random

## Description
Write a C program that embeds a hidden word within a long string of random lowercase letters.
The user must guess the hidden word.
1. **Preparation**:
    - Define a list of short words (e.g., "tree", "cat"). Randomly select a Target Word.
2. **String Assembly**: The core difficulty is manually constructing the string, exactly 30 characters long, by combining the target word with required amount of noise. You must:
    - Calculate the amount of random noise needed (50 - Target Word Length). *Note: The problem description says 30 in text but example suggests longer? Actually example input is 30. Let's assume 30.*
    *Correction: PDF says "exactly 30-character long". Then bullet point says "Calculate ... (50 - Target...)". This is a contradiction in the PDF. I will stick to "exactly 30" as per the explicit text, or maybe 50? Example 1 "xfqpjrtaqgbluetreerwqmnvzpsikl" is 30 chars. So 30 is correct. Typos in exam questions happen.*
    - Randomly select a starting insertion index for the Target Word.
    - Assemble and display the string by filling array positions with the correct mix of noise characters (before and after the insertion point) and the Target Word.
3. **Game Loop**: Repeatedly prompt the user until they correctly guess the Target Word.

## Examples
```text
Input: xfqpjrtaqgbluetreerwqmnvzpsikl
Output: Correct Guess: tree
```
```text
Input: prkbaacatdfuvmqlnzxweqroiutmbc
Output: Correct Guess: cat
```
```text
Input: mznxqowlkbuterflyprqvmaopstlxq
Output: Correct Guess: fly
```


