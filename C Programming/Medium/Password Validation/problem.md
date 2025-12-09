# 🟡 Password Strength Validator

**Recommended Time:** 15 - 25 min

**Topics:** Strings, Characters, Logic

## Description

Write a function that evaluates the strength of a given password string. The function should calculate a score based on the following criteria:

1.  **Length Requirement:** The password must be at least 8 characters long. If it is shorter than 8 characters, the strength is **0**.
2.  **Base Score:** If the password meets the length requirement, it starts with a base strength of **1**.
3.  **Bonuses:** Add **1** point for each of the following categories present in the password:
    - **Uppercase:** Contains at least one uppercase letter (`A`-`Z`).
    - **Lowercase:** Contains at least one lowercase letter (`a`-`z`).
    - **Alphabetic:** Contains at least two alphabetic letters (`a`-`z` or `A`-`Z`)
    - **Digit:** Contains at least three numeric digit (`0`-`9`).
    - **Alphanumeric:** Contains at least four alphanumeric characters (`a`-`z` or `A`-`Z` or `0`-`9`)
    - **Special Character:** Contains at least five character that is not a letter or a digit (e.g., `!`, `@`, `#`).

The maximum possible strength score is **7**.

## Input / Output

- **Input:** A string `password`.
- **Output:** An integer representing the strength score (0 to 7).

## Additional Functions

Alongside all the other ctype functions you should know for the exam, you need two more in this problem:

`bool isdigit(char cr)` 

Returns true if the character is a digit, false otherwise

<br>

`bool isalpha(char cr)`

Returns true if the character is alphabetic (it's a letter uppercase or lowercase)

## Examples

```text
Example 1:
Input: password = "short"
Output: 0
Explanation: Length is less than 8.
```

```
Example 2:
Input: password = "password"
Output: 4
Explanation:
- Length >= 8 (Base score: 1)
- Contains lowercase (+1)
- Contains alphabetic (8 letters >= 2) (+1)
- Contains alphanumeric (8 chars >= 4) (+1)
- Total: 4
```

```
Example 3:
Input: password = "Password1"
Output: 5
Explanation:
- Length >= 8 (Base score: 1)
- Contains uppercase (+1)
- Contains lowercase (+1)
- Contains alphabetic (8 letters >= 2) (+1)
- Contains alphanumeric (9 chars >= 4) (+1)
- Contains digit (1 digit < 3, no bonus)
- Total: 5
```

```
Example 4:
Input: password = "P@ssword1"
Output: 5
Explanation:
- Length >= 8 (Base score: 1)
- Contains uppercase (+1)
- Contains lowercase (+1)
- Contains alphabetic (7 letters >= 2) (+1)
- Contains alphanumeric (8 chars >= 4) (+1)
- Contains digit (1 digit < 3, no bonus)
- Contains special character (1 char < 5, no bonus)
- Total: 5
```
