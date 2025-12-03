# 🟢 Two Sum

> Also in *Daylen APSC 160 MT2 Practice Problems*

**Recommended Time:** 5-10 min 

**Topics:** Arrays, Loops, Control

## Description
Given an array of integers `nums` and an integer `target`, return the sum of the **two indices** of the two numbers such that they add up to `target`.


## Input / Output
* **Input:** `int nums[]`, `int numsSize`, `int target`
* **Output:** Return the smallest sum of indices possible, or `-1` if not possible.

## Requirements
* You may not use the same element twice.
* If there is a tie, return the smaller sum of indices.
* If no two sums are possible, return `-1`.


## Examples

```text
Input: [2, 7, 11, 15], 4, 9
Output: 1
Explanation: nums[0] + nums[1] == 9, so we return 0 + 1 = 1.
```

```text
Input: [3, 2, 4], 3, 6
Output: 3
```

```text
Input: [3, 3], 2, 6
Output: 1
```

```text
Input: [1, 2, 3, 4], 4, 10
Output: -1
```