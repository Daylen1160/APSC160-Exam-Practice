# 🟡 Divisible Factors

> Also in *Daylen APSC 160 MT2 Practice Problems*

**Recommended Time:** 10 - 20 min

**Topics:** File I/O, Arrays, Loops, Control

## Description
Write a function that writes all factors of the integer `n` to a file named `factors.txt`, then reads all the values from `factors.txt` that are divisible by `d` into `output_array`. Return the number of array entries in `output_array` that were changed from `0` to a divisor (i.e., the number of non-garbage values you wrote).

When passed in, assume `output_array` initially contains only `0`s and has enough capacity for all divisors. Assume `n` and `d` are non-zero.

## Input / Output
- **Input:** `int n`, `int d`, `int output_array[]`
- **Modifies:** Writes the factors of `n` (space-separated) into `factors.txt`. Also writes the divisors of `n` that are divisible by `d` into `output_array` (overwriting zeros).
- **Output:** Return the number of values you assigned into `output_array` (the count of divisors divisible by `d`).

## Requirements
- Write and read to `factors.txt`
- Modify `output_array` accordingly

## Examples

```text
Example 1:
Input: n = 6, d = 3
Modifies: factors.txt contains "1 2 3 6" and output_array becomes [3, 6]
Output: 2

Explanation: The factors of 6 are 1, 2, 3, and 6. Of those, 3 and 6 are divisible by 3 so we store them in `output_array` and return 2.
```

```text
Example 2:
Input: n = 30, d = 5
Modifies: factors.txt contains "1 2 3 5 6 10 15 30" and output_array becomes [5, 10, 15, 30]
Output: 4
```
