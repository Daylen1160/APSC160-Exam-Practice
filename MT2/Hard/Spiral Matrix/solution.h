/**
 * @file solution.h
 * @brief Spiral Matrix Solution
 * @author Daylen Chun
 */

void spiralOrder(int NUMROWS, int NUMCOLS, int matrix[][NUMCOLS], int result[]);

/**
 * @brief Traverse matrix in spiral order and store values in result array
 * @param[in] NUMROWS       Number of rows in matrix
 * @param[in] NUMCOLS       Number of columns in matrix
 * @param[in] matrix        The input matrix
 * @param[in, out] result   Spiral order output array (size NUMROWS * NUMCOLS)
 * @modifies result array
 */
void spiralOrder(int NUMROWS, int NUMCOLS, int matrix[][NUMCOLS], int result[]) {
    int top = 0;              // Boundary at 0/top row
    int bottom = NUMROWS - 1; // Boundary at NUMROWS-1/bottom row
    int left = 0;             // Boundary at 0/leftmost column
    int right = NUMCOLS - 1;  // Boundary at NUMCOLS-1/rightmost column

    int index = 0; // Index for result

    while (left <= right && top <= bottom) {
        // Left --> Right
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;

        // Top --> Bottom
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // We have to put an if statement for these two because the two for loops
        // above could have violated the while loop condition already

        // Right --> Left
        if (top <= bottom) { // If we aren't done with going across columns (because there's still some height width)
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }

        // Bottom --> Top
        if (left <= right) { // If we aren't done with going across rows (because there's still some column width)
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
}

