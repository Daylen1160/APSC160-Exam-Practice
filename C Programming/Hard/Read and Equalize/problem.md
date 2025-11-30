# 🔴 Read and Equalize

> Also in *Daylen APSC 160 MT2 Practice Problems*

**Recommended Time:** 15 - 45 min

**Topics:** File I/O, Arrays, Functions, Control, Fundamentals

## Description
Read numbers from a file in a 2-column format. Based on whether a given number `evenOrOdd` is even or odd:
- **Even:** Read only the numbers in the right column.
- **Odd:** Read only the numbers in the left column.

Store the selected values in an array. Then determine the minimum number of elements to remove from the array so that all remaining elements have the same value.

## Input / Output
- **Input:** 
  - `char fileName[]` — the name of the file to read from.
  - `int fileRows` — the number of rows in the file.
  - `int evenOrOdd` — a number whose parity determines which column to read.
- **Output:** 
  - Return the minimum number of elements to remove so that all remaining elements are equal.


## Examples

```text
Example 1:
File content (test1.txt):
1 4
1 3
4 8
1 6
11 6

Input: test1.txt, 5, 50
Output: 3

Explanation: 
- 50 is even, so read the right column: [4, 3, 8, 6, 6].
- To get the same number in the array, we can see that removing [4, 3, 8] removes the minimum number of elements to ensure the rest of the array contains the same element, so we output 3. 
```

```text
Example 2:
File content (test1.txt):
1 4
1 3
4 8
1 6
11 6

Input: test1.txt, 5, 51
Output: 2
```
