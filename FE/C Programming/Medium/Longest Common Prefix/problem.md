
# 🟡 Longest Common Prefix

**Recommended Time:** 10 - 20 min

**Topics:** Branching, Loops, Functions, 1D Array, 2D Array, String

## Description

Write a function to find the longest common prefix string among an array of strings.

If there is no common prefix, return an empty string `""`.

## Input / Output

- **Input:** 
    - `char strs[][]`: An array of strings and an
    - `int strsLength`: The number of strings
    - `char longestPrefix[]`: The longest prefix shared among the strings
- **Modify:** Set `longestPrefix[]` to contain the longest common prefix (or empty string if none).
- **Output:** The length of `longestPrefix[]`

## Examples

```text
Example 1:
Input: strs = ["flower","flow","flight"], 3, ""
Modifies: "fl"
Output: 2
Explanation: All the strings passed in start with at least "fl"
```

```
Example 2:
Input: strs = ["dog","racecar","car"], 3 ""
Modifies: ""
Output: 0
Explanation: There is no common prefix among the input strings.
```




