# 🔴 Spiral Matrix

**Recommended Time:** 20 - 45 min

**Topics:** Branching, Loops, Functions, 1D Array, 2D Array

## Description
Given an `m x n` matrix, return all elements of the matrix in spiral order.

Spiral order means:
1. Traverse left to right across the top row.
2. Traverse top to bottom down the right column.
3. Traverse right to left across the bottom row.
4. Traverse bottom to top up the left column.
5. Repeat for the inner submatrix until all elements are visited.

## Input / Output

- **Input:** `int NUMROWS`, `int NUMCOLS`, `int matrix[][NUMCOLS]`
- **Modifies:** `result[]` with the matrix values in spiral order.

## Examples

```text
Example 1:
Input: 3, 3, [[1,2,3],[4,5,6],[7,8,9]]
Output (result): [1,2,3,6,9,8,7,4,5]
```

![Spiral Matrix Example 1](../../../img/spiralmatrix1.jpg "Spiral Matrix Example 1")

```text
Example 2:
Input: 3, 4, [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output (result): [1,2,3,4,8,12,11,10,9,5,6,7]
```

![Spiral Matrix Example 2](../../../img/spiralmatrix2.jpg "Spiral Matrix Example 2")

## Hints
- Track four boundaries: `top`, `bottom`, `left`, `right`.
- After each directional traversal, shrink one boundary.
- Be sure to check boundary validity before a traversal (you already traversed it)

## Credits

https://leetcode.com/problems/spiral-matrix/
