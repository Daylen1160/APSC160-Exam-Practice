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

    for (int i = 0; i < NUMROWS; i++) {
        zeroRows[i] = 0;
    }

    for (int j = 0; j < NUMCOLS; j++) {
        zeroCols[j] = 0;
    }

    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }

    for (int i = 0; i < NUMROWS; i++) {
        for (int j = 0; j < NUMCOLS; j++) {
            if (zeroRows[i] == 1 || zeroCols[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
