// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "solution.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>

static int boardsEqual(int rows, int cols, int a[][cols], int b[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

static void printBoard(int rows, int cols, int b[][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            printf("%d", b[i][j]);
            if (j + 1 < cols) printf(",");
        }
        printf("]\n");
    }
}

int main() {
    printf("Running Game Of Life Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (Example 1) ---
    totalTests++;
    int board1[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    int expected1[4][3] = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    gameOfLife(4, 3, board1);
    if (boardsEqual(4, 3, board1, expected1)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printBoard(4,3, expected1);
        printf("  Actual:\n"); printBoard(4,3, board1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2 (Example 2) ---
    totalTests++;
    int board2[2][2] = {{1,1},{1,0}};
    int expected2[2][2] = {{1,1},{1,1}};
    gameOfLife(2, 2, board2);
    if (boardsEqual(2, 2, board2, expected2)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printBoard(2,2, expected2);
        printf("  Actual:\n"); printBoard(2,2, board2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3 (Blinker oscillator) ---
    totalTests++;
    int board3[3][3] = {{0,1,0},{0,1,0},{0,1,0}};
    int expected3[3][3] = {{0,0,0},{1,1,1},{0,0,0}};
    gameOfLife(3, 3, board3);
    if (boardsEqual(3, 3, board3, expected3)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printBoard(3,3, expected3);
        printf("  Actual:\n"); printBoard(3,3, board3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4 (Stable block) ---
    totalTests++;
    int board4[2][2] = {{1,1},{1,1}}; // block stays the same
    int expected4[2][2] = {{1,1},{1,1}};
    gameOfLife(2, 2, board4);
    if (boardsEqual(2, 2, board4, expected4)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printBoard(2,2, expected4);
        printf("  Actual:\n"); printBoard(2,2, board4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5 (Single cell dies) ---
    totalTests++;
    int board5[1][1] = {{1}};
    int expected5[1][1] = {{0}};
    gameOfLife(1, 1, board5);
    if (boardsEqual(1, 1, board5, expected5)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected:\n"); printBoard(1,1, expected5);
        printf("  Actual:\n"); printBoard(1,1, board5);
    }
    printf("----------------------------------------\n");

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}
