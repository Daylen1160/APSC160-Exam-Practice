// Change this to "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char* boolToString(bool b);

int main() {
    printf("Running isPalindrome Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1: Standard Palindrome (Odd Length) ---
    totalTests++;
    char input1[] = "racecar";
    bool expected1 = true;
    bool actual1 = isPalindrome(input1);

    if (actual1 == expected1) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input1);
        printf("  Expected: %s\n", boolToString(expected1));
        printf("  Actual:   %s\n", boolToString(actual1));
    }
    printf("----------------------------------------\n");

    // --- Test Case 2: Standard Palindrome (Even Length) ---
    totalTests++;
    char input2[] = "noon";
    bool expected2 = true;
    bool actual2 = isPalindrome(input2);

    if (actual2 == expected2) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input2);
        printf("  Expected: %s\n", boolToString(expected2));
        printf("  Actual:   %s\n", boolToString(actual2));
    }
    printf("----------------------------------------\n");

    // --- Test Case 3: Non-Palindrome ---
    totalTests++;
    char input3[] = "hello";
    bool expected3 = false;
    bool actual3 = isPalindrome(input3);

    if (actual3 == expected3) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input3);
        printf("  Expected: %s\n", boolToString(expected3));
        printf("  Actual:   %s\n", boolToString(actual3));
    }
    printf("----------------------------------------\n");

    // --- Test Case 4: Single Character (Always True) ---
    totalTests++;
    char input4[] = "a";
    bool expected4 = true;
    bool actual4 = isPalindrome(input4);

    if (actual4 == expected4) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input4);
        printf("  Expected: %s\n", boolToString(expected4));
        printf("  Actual:   %s\n", boolToString(actual4));
    }
    printf("----------------------------------------\n");

    // --- Test Case 5: Case Sensitivity ---
    totalTests++;
    char input5[] = "Racecar";
    bool expected5 = false; 
    bool actual5 = isPalindrome(input5);

    if (actual5 == expected5) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input5);
        printf("  Expected: %s\n", boolToString(expected5));
        printf("  Actual:   %s\n", boolToString(actual5));
    }
    printf("----------------------------------------\n");

    // --- Test Case 6: Empty String ---
    totalTests++;
    char input6[] = "";
    bool expected6 = true;
    bool actual6 = isPalindrome(input6);

    if (actual6 == expected6) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input:    \"%s\"\n", input6);
        printf("  Expected: %s\n", boolToString(expected6));
        printf("  Actual:   %s\n", boolToString(actual6));
    }
    printf("----------------------------------------\n");

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}

/**
 * Helper function to convert bool to string for printing
 */
const char* boolToString(bool b) {
    return b ? "true" : "false";
}