// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "solution.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <string.h>

static int printTestResult(int testNum, int expected, int actual, const char *input) {
    if (expected == actual) {
        printf("Test Case %d: PASS\n", testNum);
        printf("----------------------------------------\n");
        return 1;
    } else {
        printf("Test Case %d: FAIL\n", testNum);
        printf("  Input:    \"%s\"\n", input);
        printf("  Expected: %d\n", expected);
        printf("  Actual:   %d\n", actual);
        printf("----------------------------------------\n");
        return 0;
    }
}

int main() {
    printf("Running Password Validation Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (Example 1: Length < 8) ---
    totalTests++;
    char input1[] = "short";
    int expected1 = 0;
    int actual1 = passwordStrengthValidator(input1);
    passedTests += printTestResult(totalTests, expected1, actual1, input1);

    // --- Test Case 2 (Example 2: Base + Lower + Alpha + Alnum) ---
    // "password"
    // Length 8 (1)
    // Lower 'p' (1)
    // Alpha 8 (1)
    // Alnum 8 (1)
    // Upper 0, Digit 0, Special 0
    // Total: 4
    totalTests++;
    char input2[] = "password";
    int expected2 = 4;
    int actual2 = passwordStrengthValidator(input2);
    passedTests += printTestResult(totalTests, expected2, actual2, input2);

    // --- Test Case 3 (Example 3: Base + Upper + Lower + Alpha + Alnum) ---
    // "Password1"
    // Length 9 (1)
    // Upper 'P' (1)
    // Lower 'a' (1)
    // Alpha 8 (1)
    // Alnum 9 (1)
    // Digit 1 (0, needs 3)
    // Special 0
    // Total: 5
    totalTests++;
    char input3[] = "Password1";
    int expected3 = 5;
    int actual3 = passwordStrengthValidator(input3);
    passedTests += printTestResult(totalTests, expected3, actual3, input3);

    // --- Test Case 4 (Example 4: Base + Upper + Lower + Alpha + Alnum) ---
    // "P@ssword1"
    // Length 9 (1)
    // Upper 'P' (1)
    // Lower 's' (1)
    // Alpha 7 (1)
    // Alnum 8 (1)
    // Digit 1 (0, needs 3)
    // Special 1 (0, needs 5)
    // Total: 5
    totalTests++;
    char input4[] = "P@ssword1";
    int expected4 = 5;
    int actual4 = passwordStrengthValidator(input4);
    passedTests += printTestResult(totalTests, expected4, actual4, input4);

    // --- Test Case 5 (Max Score: All Bonuses) ---
    // "AaBbCc123!!!!!"
    // Length 14 (1)
    // Upper (1)
    // Lower (1)
    // Alpha 6 (1)
    // Digit 3 (1)
    // Alnum 9 (1)
    // Special 5 (1)
    // Total: 7
    totalTests++;
    char input5[] = "AaBbCc123!!!!!";
    int expected5 = 7;
    int actual5 = passwordStrengthValidator(input5);
    passedTests += printTestResult(totalTests, expected5, actual5, input5);

    // --- Test Case 6 (Digit Threshold Edge Case) ---
    // "Password12" (2 digits, threshold is 3)
    // Length 10 (1)
    // Upper (1)
    // Lower (1)
    // Alpha 8 (1)
    // Alnum 10 (1)
    // Digit 2 (0)
    // Special 0
    // Total: 5
    totalTests++;
    char input6[] = "Password12";
    int expected6 = 5;
    int actual6 = passwordStrengthValidator(input6);
    passedTests += printTestResult(totalTests, expected6, actual6, input6);

    // --- Test Case 7 (Digit Threshold Met) ---
    // "Password123" (3 digits)
    // Length 11 (1)
    // Upper (1)
    // Lower (1)
    // Alpha 8 (1)
    // Alnum 11 (1)
    // Digit 3 (1)
    // Special 0
    // Total: 6
    totalTests++;
    char input7[] = "Password123";
    int expected7 = 6;
    int actual7 = passwordStrengthValidator(input7);
    passedTests += printTestResult(totalTests, expected7, actual7, input7);

    // --- Test Case 8 (Special Threshold Edge Case) ---
    // "Pass!!!!" (4 specials, threshold is 5)
    // Length 8 (1)
    // Upper (1)
    // Lower (1)
    // Alpha 4 (1)
    // Alnum 4 (1)
    // Digit 0
    // Special 4 (0)
    // Total: 5
    totalTests++;
    char input8[] = "Pass!!!!";
    int expected8 = 5;
    int actual8 = passwordStrengthValidator(input8);
    passedTests += printTestResult(totalTests, expected8, actual8, input8);

    // --- Test Case 9 (Special Threshold Met) ---
    // "Pass!!!!!" (5 specials)
    // Length 9 (1)
    // Upper (1)
    // Lower (1)
    // Alpha 4 (1)
    // Alnum 4 (1)
    // Digit 0
    // Special 5 (1)
    // Total: 6
    totalTests++;
    char input9[] = "Pass!!!!!";
    int expected9 = 6;
    int actual9 = passwordStrengthValidator(input9);
    passedTests += printTestResult(totalTests, expected9, actual9, input9);

    // --- Test Case 10 (Alpha Threshold Edge Case) ---
    // "1234567A" (1 alpha, threshold is 2)
    // Length 8 (1)
    // Upper (1)
    // Lower (0)
    // Alpha 1 (0)
    // Alnum 8 (1)
    // Digit 7 (1)
    // Special 0
    // Total: 4
    totalTests++;
    char input10[] = "1234567A";
    int expected10 = 4;
    int actual10 = passwordStrengthValidator(input10);
    passedTests += printTestResult(totalTests, expected10, actual10, input10);

    // --- Test Case 11 (Alnum Threshold Edge Case) ---
    // "!!!@@@A1" (2 alnum, threshold is 4)
    // Length 8 (1)
    // Upper (1)
    // Lower (0)
    // Alpha 1 (0)
    // Digit 1 (0)
    // Alnum 2 (0)
    // Special 6 (1)
    // Total: 3
    totalTests++;
    char input11[] = "!!!@@@A1";
    int expected11 = 3;
    int actual11 = passwordStrengthValidator(input11);
    passedTests += printTestResult(totalTests, expected11, actual11, input11);

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}
