# 🟢 Random Text Mutation

**Recommended Time:** 15 - 20 min

**Topics:** Branching, Loops, Functions, 1D Array, Files I/O, String, User I/O

## Description
Write a C program that reads a single lowercase word (string) from the user and applies exactly one random mutation from the list below, printing the result. The program should handle a string maximum length of 50. Repeatedly print an error message if the user provides a string greater than the allowed length until an acceptable string is entered.

Note: All mutations must be performed in-place, meaning they do not change the string length.

1. **Uppercase**: Uppercase a random character in the string.
2. **Replace**: Replace a random character in the string with the literal character Ã¢â‚¬Ëœ*Ã¢â‚¬â„¢
3. **Swap Ends**: Swap the first and the last characters of the string.

## Examples
```text
Input: hello
Output: helLo (Mutation: Uppercase 'l')
```
```text
Input: programming
Output: grogramminp (Mutation: Swap Ends)
```
```text
Input: student
Output: st*dent (Mutation: Replace 'u' with '*')
```
```text
Input: iamsinglehandedlythebestprogrammingstudentintheentirewideworld
Output: String exceeds maximum character limit. Please try again.
```


