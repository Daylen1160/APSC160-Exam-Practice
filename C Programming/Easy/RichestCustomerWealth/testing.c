// Change this to either template.c or solution.c to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>

int main() {
    printf("Running Richest Customer Wealth Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (Example 1) ---
    totalTests++;
    int accounts1[2][3] = {{1,2,3}, {3,2,1}};
    int attempt1 = richestCustomerWealth(2, 3, accounts1);
    int answer1 = 6;
    if (attempt1 == answer1) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt1);
        printf("  Expected: %d\n", answer1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2 (Example 2) ---
    totalTests++;
    int accounts2[3][2] = {{1,5}, {7,3}, {3,5}};
    int attempt2 = richestCustomerWealth(3, 2, accounts2);
    int answer2 = 10;
    if (attempt2 == answer2) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt2);
        printf("  Expected: %d\n", answer2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3 (Example 3) ---
    totalTests++;
    int accounts3[3][3] = {{2,8,7}, {7,1,3}, {1,9,5}};
    int attempt3 = richestCustomerWealth(3, 3, accounts3);
    int answer3 = 17;
    if (attempt3 == answer3) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt3);
        printf("  Expected: %d\n", answer3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4 (Single Customer) ---
    totalTests++;
    int accounts4[1][5] = {{10, 0, 5, 3, 2}};
    int attempt4 = richestCustomerWealth(1, 5, accounts4);
    int answer4 = 20;
    if (attempt4 == answer4) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt4);
        printf("  Expected: %d\n", answer4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5 (Zeros) ---
    totalTests++;
    int accounts5[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int attempt5 = richestCustomerWealth(3, 3, accounts5);
    int answer5 = 0;
    if (attempt5 == answer5) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt5);
        printf("  Expected: %d\n", answer5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6 (Large values) ---
    totalTests++;
    int accounts6[2][4] = {{100000, 200000, 300000, 400000}, {500000, 0, 0, 0}}; // sums: 1000000 and 500000
    int attempt6 = richestCustomerWealth(2, 4, accounts6);
    int answer6 = 1000000;
    if (attempt6 == answer6) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt6);
        printf("  Expected: %d\n", answer6);
    }
    printf("----------------------------------------\n");

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}
