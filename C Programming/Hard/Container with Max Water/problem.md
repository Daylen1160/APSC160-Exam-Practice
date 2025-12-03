# 🔴Container With Max Water

> Also in *Daylen APSC 160 MT2 Practice Problems*

**Recommended Time:** 30 - 45 min

**Topics:** Arrays, Loops, Control

## Description
You are given an integer array `height` of length `heightSize`. There are `heightSize` vertical lines drawn such that the two endpoints of the i-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water. You may not slant the container — the sides must be vertical at indices i and j.

## Constraints
- `0 <= i < j < heightSize` (indices are integer positions along the x-axis)
## Input / Output
- **Input:** `int height[]`, `int heightSize`
- **Output:** Return the maximum amount of water the container can store (an integer).

## Examples

```text
Example 1:
Input: [1,8,6,2,5,4,8,3,7], 9
Output: 49

Explanation: The maximum area is formed between the lines at index 1 (height 8) and index 8 (height 7): area = (8 - 1) * min(8,7) = 7 * 7 = 49.
```
![Max Water Graph](../../../img/maxwater.jpg "Max Water Graph")

```text
Example 2:
Input: [1,1], 2
Output: 1

Explanation: Only two lines, area = (1 - 0) * min(1,1) = 1.
```


---

**Hints:**
- There are two common approaches:
  - Brute force: try all pairs `(i, j)` and compute area — O(n^2).
  - Two-pointer: start with left=0 and right=heightSize-1, compute area, then move the pointer at the shorter line inward — O(n).
- I would advise to program the brute force method first, get that working, and then get the two-pointer solution. Getting both solutions working is highly recommended.
