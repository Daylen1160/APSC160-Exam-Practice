/**
 * @file solution.h
 * @brief Game of Life Solution
 * @author Daylen Chun
 */

 void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]);
void copyBoard(int NUMROWS, int NUMCOLS, int source[][NUMCOLS], int dest[][NUMCOLS]);
int getLiveNeighbors(int NUMROWS, int NUMCOLS, int board[][NUMCOLS], int row, int col);
int liveCellNextState(int liveNeighbors);
int deadCellNextState(int liveNeighbors);

/**
 * @brief Update the board to the next state according to the Game of Life rules
 * @param[in] NUMROWS    Number of rows in the board
 * @param[in] NUMCOLS    Number of columns in the board
 * @param     board      The game board
 * @modifies board to its next state
 */
void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]) {
    int originalBoard[NUMROWS][NUMCOLS];
    int nextBoard[NUMROWS][NUMCOLS];

    copyBoard(NUMROWS, NUMCOLS, board, originalBoard);

    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            int liveNeighbors = getLiveNeighbors(NUMROWS, NUMCOLS, originalBoard, i, j);
            if (originalBoard[i][j] == 1) {
                nextBoard[i][j] = liveCellNextState(liveNeighbors);
            } else {
                nextBoard[i][j] = deadCellNextState(liveNeighbors);
            }
        }
    }

    copyBoard(NUMROWS, NUMCOLS, nextBoard, board);
}

/**
 * @brief Calculate the number of live neighbors for a given cell
 * @param[in] NUMROWS    Number of rows in the board
 * @param[in] NUMCOLS    Number of columns in the board
 * @param[in] board      The game board
 * @param[in] row        The row index of the cell
 * @param[in] col        The column index of the cell
 * @return The number of live neighbors surrounding the cell
 */
int getLiveNeighbors(int NUMROWS, int NUMCOLS, int board[][NUMCOLS], int row, int col) {
    int liveNeighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                int neighborRow = row + i;
                int neighborCol = col + j;
                if (neighborRow >= 0 && neighborRow < NUMROWS && neighborCol >= 0 && neighborCol < NUMCOLS) {
                    liveNeighbors += board[neighborRow][neighborCol];
                }
            }
        }
    }
    return liveNeighbors;
}

/**
 * @brief Determine the next state of a live cell based on its live neighbors
 * @param[in] liveNeighbors The number of live neighbors surrounding the live cell
 * @return The next state of the live cell (1 for alive, 0 for dead)
 */
int liveCellNextState(int liveNeighbors) {
    int live = 0;
    if (liveNeighbors == 2 || liveNeighbors == 3) {
        live = 1;
    }
    return live;
}

/**
 * @brief Determine the next state of a dead cell based on its live neighbors
 * @param[in] liveNeighbors The number of live neighbors surrounding the dead cell
 * @return The next state of the dead cell (1 for alive, 0 for dead)
 */
int deadCellNextState(int liveNeighbors) {
    int live = 0;
    if (liveNeighbors == 3) {
        live = 1;
    }
    return live;
}

/**
 * @brief Copy the contents of source board to destination board
 * @param[in] NUMROWS    Number of rows in the board
 * @param[in] NUMCOLS    Number of columns in the board
 * @param[in] source     The source board to copy from
 * @param[out] dest      The destination board to copy to
 * @modifies dest to contain the values in source
 */
void copyBoard(int NUMROWS, int NUMCOLS, int source[][NUMCOLS], int dest[][NUMCOLS]) {
    for (int row = 0; row < NUMROWS; row++) {
        for (int col = 0; col < NUMCOLS; col++) {
            dest[row][col] = source[row][col];
        }
    }
}