# 🟡 Alien Language

**Recommended Time:** 10 - 30 min

**Topics:** File I/O, Strings, Characters, Encoding

> Note: This problem seems to not work on OnlineGDB for now. Updates coming soon.

## Description

You want to communicate with aliens. They speak a special language though that requires advanced decoding.

The encoding rules are as follows:

- Uppercase and lowercase characters are treated the same as their uppercase character, and they both are mapped to their uppercase character ASCII value - 32 in decimal.
- Any number is mapped to the length of the sentence in ASCII.
- Everything else is left alone.

Take an input from the user (the sentence you want to translate), and write it to `decoder.txt`. In the same file on the next line, display the translated sentence.


## Input / Output

- **Input:** A sentence (it has more than one word)
- **Output:** In the file named `decoder.txt` containing two lines:
	1. The original sentence (exactly as entered **without the new line**).
	2. The encoded sentence.

## ASCII Table
![ASCII_table](../../../img/ascii.gif "ASCII_table")

## How to test

Testing is a bit different than all the other problems. You need to run `template.c` or `solution.c` first to get the text in `decoder.txt`, then run `testing.c` without including either file.

## Additional Functions

Alongside all the other ctype functions you should know for the exam, you might need one more in this problem:

`bool isdigit(char cr)` 

Returns true if the character is a digit, false otherwise

## Examples

```text
Example 1:
Input: "APSC160 is the best course in first year engineering!"

Output (in decoder.txt):
APSC160 is the best course in first year engineering!
!03#555 )3 4(% "%34 #/523% ). &)234 9%!2 %.').%%2).'!

Explanation:
- The letters 'C' and 'c' are treated the same, they both get mapped to '#' (67-32=35)
- The length of the string is 53, which is the ASCII value for '5'
- Spaces and punctuation is the same
```
