# 🔴 Game Of Life

**Recommended Time:** 30 - 45 min

**Topics:** 2D Arrays/Matricies, Nested loops

## Description

The board is an `m x n` grid of cells, where each cell is either live (`1`) or dead (`0`). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following rules:

- Any live cell with fewer than two live neighbors dies (under-population).
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies (over-population).
- Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state. Given the current state of the board, update the board to its next state in-place (you do not need to return anything).


## Input / Output

- **Input:** `int NUMROWS`, `int NUMCOLS`, `int board[][]`
- **Output:** Modify `board` in-place to represent the next state according to the rules above.

## Examples


```text
Input: 4, 3, [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

![Board1](../../../img/board1.jpg "Board1")


```text
Input: 2, 2, [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

![Board2](../../../img/board2.jpg "Board2")

## Hints:
- I would strongly recommend making helper functions. Here are the ones I used:
    - `copyBoard`: Copies a matrix to another matrix
    - `getLiveNeighbours`: Gets the number of live neighbors next to the current cell
    - `liveCellNextState`: Determines the next state of a live cell based on the number of alive neighbors
    - `deadCellNextState`: Determines the next state of a dead cell based on the number of alive neighbors
- Remember that the new states of cells are based on the original states of cells. (e.g. if you change a cell, then iterate, you should not be looking at the new, updated value, you should be looking at the original value)


