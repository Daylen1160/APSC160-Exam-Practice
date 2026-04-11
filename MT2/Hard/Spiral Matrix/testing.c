// Change this to either "template.h" or "solution.h" to test
#include "solution.h"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>

static int arraysEqual(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

static void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i + 1 < n) {
            printf(",");
        }
    }
    printf("]\n");
}

int main(void) {
    printf("Running Spiral Matrix Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (3x3 square) ---
    totalTests++;
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int expected1[9] = {1,2,3,6,9,8,7,4,5};
    int actual1[9] = {0};
    spiralOrder(3, 3, matrix1, actual1);
    if (arraysEqual(actual1, expected1, 9)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected1, 9);
        printf("  Actual:   "); printArray(actual1, 9);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2 (3x4 rectangle) ---
    totalTests++;
    int matrix2[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int expected2[12] = {1,2,3,4,8,12,11,10,9,5,6,7};
    int actual2[12] = {0};
    spiralOrder(3, 4, matrix2, actual2);
    if (arraysEqual(actual2, expected2, 12)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected2, 12);
        printf("  Actual:   "); printArray(actual2, 12);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3 (single row) ---
    totalTests++;
    int matrix3[1][4] = {{3,4,5,6}};
    int expected3[4] = {3,4,5,6};
    int actual3[4] = {0};
    spiralOrder(1, 4, matrix3, actual3);
    if (arraysEqual(actual3, expected3, 4)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected3, 4);
        printf("  Actual:   "); printArray(actual3, 4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4 (single column) ---
    totalTests++;
    int matrix4[4][1] = {{3},{4},{5},{6}};
    int expected4[4] = {3,4,5,6};
    int actual4[4] = {0};
    spiralOrder(4, 1, matrix4, actual4);
    if (arraysEqual(actual4, expected4, 4)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected4, 4);
        printf("  Actual:   "); printArray(actual4, 4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5 (2x2 matrix) ---
    totalTests++;
    int matrix5[2][2] = {{1,2},{3,4}};
    int expected5[4] = {1,2,4,3};
    int actual5[4] = {0};
    spiralOrder(2, 2, matrix5, actual5);
    if (arraysEqual(actual5, expected5, 4)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected5, 4);
        printf("  Actual:   "); printArray(actual5, 4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6 (4x3 rectangle) ---
    totalTests++;
    int matrix6[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int expected6[12] = {1,2,3,6,9,12,11,10,7,4,5,8};
    int actual6[12] = {0};
    spiralOrder(4, 3, matrix6, actual6);
    if (arraysEqual(actual6, expected6, 12)) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Expected: "); printArray(expected6, 12);
        printf("  Actual:   "); printArray(actual6, 12);
    }
    printf("----------------------------------------\n");

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");
    return 0;
}
