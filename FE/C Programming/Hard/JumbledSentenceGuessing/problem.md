# 🔴🔴🔴 EXTRA-HARD Problem: Jumbled Sentence Guessing

**Recommended Time:** 45 - 90 min

**Topics:** Branching, Loops, User I/O, Functions, 1D Array, 2D Array, Files I/O, String, Random

## Description
Write a C program that implements a word-reordering puzzle.
1. **Data Storage**: Store a list of at least four short sentences in your program, where each sentence contains exactly five words.
2. **Selection & Preparation**: The program must randomly select one of these sentences.
3. **Jumbling**: The selected sentence must be split into its five individual words. The order of these five words must then be randomly shuffled.
4. **Display & Guessing**: The program must display the resulting jumbled sequence. It should then repeatedly prompt the user to input their guess for the original sentence.
5. **Winning Condition**: The program ends when the user's guess exactly matches the original sentence. The game specifies they "guessed" correctly.


## Examples
```text
outside playing children the are 

the outside are playing children
the children are playing outside
You guessed correctly!
```
```text
homework my the cat ate 

the homework ate my cat
the ate my cat homework
the cat ate my homework
You guessed correctly!
```
```text
reading am I book a

I am reading a book
You guessed correctly!
```
## Note: 

We would not expect you to do this on the final...

## Hints:

- You will find the `strncpy` function useful:
    - `strncpy(char dest[], const char src[], int n`: Copies up to `n` characters from the string pointed to by `src` to the buffer pointed to by `dest`.
    - To get a substring use `src + start_index`. 
        ```c
        char sentence[] = "I am reading a book";
        char word[10];
        strncpy(word, sentence + 5, 7); // Copies "reading" into word
        word[7] = '\0'; // Null-terminate the string
        printf("%s\n", word); // Output: reading
        ```
- Writing helper functions will be nice




