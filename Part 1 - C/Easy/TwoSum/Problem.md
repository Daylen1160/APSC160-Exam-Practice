# Problem 1: Two Sum

* **Recommended Time:** 5-10 min 
* **Topics:** Arrays, Control, Fundamentals 

## Description
Given an array of integers `nums` and an integer `target`, return the sum of the **two indices** of the two numbers such that they add up to `target`.

**Constraints:**
* You may not use the same element twice.
* If there is a tie, return the smaller sum of indices
* If no two sums are possible, return `-1`[cite: 24].

## Input / Output
* **Input:** `nums` (array), `numsSize` (int), `target` (int)
* **Output:** Return the smallest sum of indices possible, or `-1` if not possible.

---

## Examples

### Example 1 
**Input:**
```c
nums = [2, 7, 11, 15]
numsSize = 4
target = 9