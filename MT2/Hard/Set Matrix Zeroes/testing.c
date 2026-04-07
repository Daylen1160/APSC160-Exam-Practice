// Change this to either "template.h" or "solution.h" to test
#include "template.h"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>

static int matricesEqual(int rows, int cols, int a[][cols], int b[][cols]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (a[r][c] != b[r][c]) {
                return 0;
            }
        }
    }
    return 1;
}

static void printMatrix(int rows, int cols, int m[][cols]) {
    for (int r = 0; r < rows; r++) {
        printf("[");
        for (int c = 0; c < cols; c++) {
            printf("%d", m[r][c]);
            if (c + 1 < cols) {
                printf(",");
            }
        }
        printf("]\n");
    }
}

int main(void) {
    printf("Running Set Matrix Zeroes Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (Example 1) ---
    totalTests++;
    int matrix1[3][3] = {{1,1,1},{1,0,1},{1,1,1}};
    int expected1[3][3] = {{1,0,1},{0,0,0},{1,0,1}};
    setMatrixZeroes(3, 3, matrix1);
    if (matricesEqual(3, 3, matrix1, expected1)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(3, 3, expected1);
        printf("  Actual:\n"); printMatrix(3, 3, matrix1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2 (Example 2) ---
    totalTests++;
    int matrix2[3][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int expected2[3][4] = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    setMatrixZeroes(3, 4, matrix2);
    if (matricesEqual(3, 4, matrix2, expected2)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(3, 4, expected2);
        printf("  Actual:\n"); printMatrix(3, 4, matrix2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3 (No zeroes: unchanged) ---
    totalTests++;
    int matrix3[2][3] = {{1,2,3},{4,5,6}};
    int expected3[2][3] = {{1,2,3},{4,5,6}};
    setMatrixZeroes(2, 3, matrix3);
    if (matricesEqual(2, 3, matrix3, expected3)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(2, 3, expected3);
        printf("  Actual:\n"); printMatrix(2, 3, matrix3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4 (All zeroes: unchanged all zeroes) ---
    totalTests++;
    int matrix4[2][2] = {{0,0},{0,0}};
    int expected4[2][2] = {{0,0},{0,0}};
    setMatrixZeroes(2, 2, matrix4);
    if (matricesEqual(2, 2, matrix4, expected4)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(2, 2, expected4);
        printf("  Actual:\n"); printMatrix(2, 2, matrix4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5 (Single row) ---
    totalTests++;
    int matrix5[1][5] = {{1,2,0,4,5}};
    int expected5[1][5] = {{0,0,0,0,0}};
    setMatrixZeroes(1, 5, matrix5);
    if (matricesEqual(1, 5, matrix5, expected5)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(1, 5, expected5);
        printf("  Actual:\n"); printMatrix(1, 5, matrix5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6 (Single column) ---
    totalTests++;
    int matrix6[4][1] = {{1},{0},{3},{4}};
    int expected6[4][1] = {{0},{0},{0},{0}};
    setMatrixZeroes(4, 1, matrix6);
    if (matricesEqual(4, 1, matrix6, expected6)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printMatrix(4, 1, expected6);
        printf("  Actual:\n"); printMatrix(4, 1, matrix6);
    }
    printf("----------------------------------------\n");

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");
    return 0;
}
