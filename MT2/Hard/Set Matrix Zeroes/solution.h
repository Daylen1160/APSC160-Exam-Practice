/**
 * @file solution.h
 * @brief Set Matrix Zeroes Solution
 * @author Daylen Chun
 */

void setMatrixZeroes(int NUMROWS, int NUMCOLS, int matrix[][NUMCOLS]);

/**
 * @brief Set matrix rows and columns to zero if any cell is zero
 * @param[in] NUMROWS    Number of rows in matrix
 * @param[in] NUMCOLS    Number of columns in matrix
 * @param     matrix     The matrix to modify in-place
 * @modifies matrix in-place
 */
void setMatrixZeroes(int NUMROWS, int NUMCOLS, int matrix[][NUMCOLS]) {
    int zeroRows[NUMROWS];
    int zeroCols[NUMCOLS];

    for (int r = 0; r < NUMROWS; r++) {
        zeroRows[r] = 0;
    }
    for (int c = 0; c < NUMCOLS; c++) {
        zeroCols[c] = 0;
    }

    for (int r = 0; r < NUMROWS; r++) {
        for (int c = 0; c < NUMCOLS; c++) {
            if (matrix[r][c] == 0) {
                zeroRows[r] = 1;
                zeroCols[c] = 1;
            }
        }
    }

    for (int r = 0; r < NUMROWS; r++) {
        for (int c = 0; c < NUMCOLS; c++) {
            if (zeroRows[r] == 1 || zeroCols[c] == 1) {
                matrix[r][c] = 0;
            }
        }
    }
}
