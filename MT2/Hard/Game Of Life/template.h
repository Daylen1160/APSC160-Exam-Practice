/**
 * @file template.h
 * @brief Game of Life Template
 * @author Daylen Chun
 */

void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]);
void copyBoard(int NUMROWS, int NUMCOLS, int [][NUMCOLS], int [][NUMCOLS]);
int getLiveNeighbors(int NUMROWS, int NUMCOLS, int board[][NUMCOLS], int row, int col);
int liveCellNextState(int);
int deadCellNextState(int);
/**
 * @brief Update the board to the next state according to the Game of Life rules
 * @param[in] NUMROWS    Number of rows in the board
 * @param[in] NUMCOLS    Number of columns in the board
 * @modifies board to its next state
 */
void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]) {
    int newBoard[NUMROWS][NUMCOLS];
    copyBoard(NUMROWS, NUMCOLS, board, newBoard);
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            int liveNeighbors = getLiveNeighbors(NUMROWS, NUMCOLS, board, i, j);
            if (board[i][j]) newBoard[i][j] = liveCellNextState(liveNeighbors);
            else newBoard[i][j] = deadCellNextState(liveNeighbors);
        }
    }
    copyBoard(NUMROWS, NUMCOLS, newBoard, board);
}

void copyBoard(int NUMROWS, int NUMCOLS, int board[][NUMCOLS], int newBoard[][NUMCOLS]){
    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
}

int getLiveNeighbors(int NUMROWS, int NUMCOLS, int board[][NUMCOLS], int row, int col) {
    int liveNeighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && row + i >= 0 && row + i < NUMROWS && col + j >= 0 && col + j < NUMCOLS)  {
                liveNeighbors += board[row + i][col + j];
            }
        }
    }
    return liveNeighbors;
}

int liveCellNextState(int numAlive) {
    if (numAlive < 2 || numAlive > 3) return 0;
    return 1;
}

int deadCellNextState(int numAlive) {
    if (numAlive == 3) return 1;
    return 0;
}