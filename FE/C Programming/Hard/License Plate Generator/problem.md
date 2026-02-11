# 🔴 Unique License Plate Generator

**Recommended Time:** 20 - 45 min

**Topics:** 2D Arrays, Strings, Random Numbers, Characters

## Description
Write a C function that generates 5 random vehicle license plates and stores them in a 2D array. Each license plate must strictly follow the format `LLL-###`, where:
* `L` is a random **uppercase letter** ('A' through 'Z').
* `-` is a fixed hyphen separator.
* `#` is a random **digit** ('0' through '9').

You must also check that no two license plates contain the same set of letters or digits.

## Input/Output

- **Input:** `char licensePlates[][]`
- **Modify:** `char licensePlates[][]` to contain valid randomized license plates
- **Output:** N/A

## ASCII Table
![ASCII_table](../../../../img/ascii.gif "ASCII_table")

## Example

| Input | Output |
| :--- | :--- |
| `licensePlates`  | `licensePlates` could contain:<br>`"ABC-123"`<br>`"XYZ-789"`<br>`"LMN-456"`<br>`"PQR-012"`<br>`"DEF-345"` |

**Explanation:**
- The letter combination (e.g., "ABC") must be unique across all 5 plates.
- The digit combination (e.g., "123") must be unique across all 5 plates.
- A plate like "ABC-999" would be invalid if "ABC" was already used in a previous plate.
- A plate like "ZZZ-123" would be invalid if "123" was already used in a previous plate.
