# 🟡 Holiday of Equality

> Also in *Daylen APSC 160 MT2 Practice Problems*

**Recommended Time:** 10 - 15 min

**Topics:** Loops, Control

## Description
In Berland it is the holiday of equality. In honor of the holiday the king decided to equalize the welfare of all citizens in Berland at the expense of the state treasury.

There are `citizensSize` citizens; the welfare of each citizen is given by integer values `a_i` (burles). As the royal treasurer, you can only give money (never take). You need to compute the minimum total number of burles the king must spend so that every citizen ends up with the same amount of money.

## Input / Output
- **Input:**
  - `citizens[]`, `citizensSize`
- **Output:**
  - Return a single integer `N` — the minimum total number of burles the king has to spend.

## Requirements
- You may only increase citizens' wealth (add non-negative integers to some entries).


## Examples

```text
Example 1:
Input:
5
0 1 2 3 4
Output:
10

Explanation: Raise values to 4: add 4, 3, 2, 1, 0 => total 10.
```

```text
Example 2:
Input:
5
1 1 0 1 1
Output:
1

Explanation: Raise the third citizen from 0 to 1 => total 1.
```

```text
Example 3:
Input:
3
1 3 1
Output:
4

Explanation: Raise first and third citizens from 1 to 3 => add 2 + 0 + 2 = 4.
```

```text
Example 4:
Input:
1
12
Output:
0

Explanation: All citizens already have 12 burles; no spending required.
```
