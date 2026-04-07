// Change this to either "template.h" or "solution.h" to test
#include "template.h"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <string.h>

int main() {
    printf("Running isPalindrome Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1: Standard Palindrome (Odd Length) ---
    totalTests++;
    char input1[] = "racecar";
    int expected1 = 1;
    int actual1 = isPalindrome(input1);

    if (actual1 == expected1) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input1);
        printf("  Expected: %d\n", expected1);
        printf("  Actual:   %d\n", actual1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2: Standard Palindrome (Even Length) ---
    totalTests++;
    char input2[] = "noon";
    int expected2 = 1;
    int actual2 = isPalindrome(input2);

    if (actual2 == expected2) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input2);
        printf("  Expected: %d\n", expected2);
        printf("  Actual:   %d\n", actual2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3: Non-Palindrome ---
    totalTests++;
    char input3[] = "hello";
    int expected3 = 0;
    int actual3 = isPalindrome(input3);

    if (actual3 == expected3) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input3);
        printf("  Expected: %d\n", expected3);
        printf("  Actual:   %d\n", actual3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4: Single Character (Always True) ---
    totalTests++;
    char input4[] = "a";
    int expected4 = 1;
    int actual4 = isPalindrome(input4);

    if (actual4 == expected4) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input4);
        printf("  Expected: %d\n", expected4);
        printf("  Actual:   %d\n", actual4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5: Case Sensitivity ---
    totalTests++;
    char input5[] = "Racecar";
    int expected5 = 0; 
    int actual5 = isPalindrome(input5);

    if (actual5 == expected5) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input5);
        printf("  Expected: %d\n", expected5);
        printf("  Actual:   %d\n", actual5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6: Empty String ---
    totalTests++;
    char input6[] = "";
    int expected6 = 1;
    int actual6 = isPalindrome(input6);

    if (actual6 == expected6) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input6);
        printf("  Expected: %d\n", expected6);
        printf("  Actual:   %d\n", actual6);
    }
    printf("----------------------------------------\n");

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");
    return 0;
}
