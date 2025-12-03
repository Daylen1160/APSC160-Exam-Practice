// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_PREFIX_LENGTH 100

static int printTestResult(int testNum, const char *expected, const char *actual, int expectedLen, int actualLen) {
    if (strcmp(expected, actual) == 0 && expectedLen == actualLen) {
        printf("Test Case %d: PASS\n", testNum);
        printf("----------------------------------------\n");
        return 1;
    } else {
        printf("Test Case %d: FAIL\n", testNum);
        printf("  Expected Prefix: \"%s\" (length %d)\n", expected, expectedLen);
        printf("  Actual Prefix:   \"%s\" (length %d)\n", actual, actualLen);
        printf("----------------------------------------\n");
        return 0;
    }
}

int main() {
    printf("Running Longest Common Prefix Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 (Example 1) ---
    totalTests++;
    char strs1[3][MAX_WORD_LENGTH] = {"flower", "flow", "flight"};
    char prefix1[MAX_PREFIX_LENGTH] = "";
    int len1 = longestCommonPrefix(strs1, 3, prefix1);
    passedTests += printTestResult(totalTests, "fl", prefix1, 2, len1);

    // --- Test Case 2 (Example 2) ---
    totalTests++;
    char strs2[3][MAX_WORD_LENGTH] = {"dog", "racecar", "car"};
    char prefix2[MAX_PREFIX_LENGTH] = "";
    int len2 = longestCommonPrefix(strs2, 3, prefix2);
    passedTests += printTestResult(totalTests, "", prefix2, 0, len2);

    // --- Test Case 3 (All identical strings) ---
    totalTests++;
    char strs3[2][MAX_WORD_LENGTH] = {"test", "test"};
    char prefix3[MAX_PREFIX_LENGTH] = "";
    int len3 = longestCommonPrefix(strs3, 2, prefix3);
    passedTests += printTestResult(totalTests, "test", prefix3, 4, len3);

    // --- Test Case 4 (Single string) ---
    totalTests++;
    char strs4[1][MAX_WORD_LENGTH] = {"alone"};
    char prefix4[MAX_PREFIX_LENGTH] = "";
    int len4 = longestCommonPrefix(strs4, 1, prefix4);
    passedTests += printTestResult(totalTests, "alone", prefix4, 5, len4);

    // --- Test Case 5 (Empty array) ---
    totalTests++;
    char strs5[1][MAX_WORD_LENGTH] = {""};
    char prefix5[MAX_PREFIX_LENGTH] = "";
    int len5 = longestCommonPrefix(strs5, 0, prefix5);
    passedTests += printTestResult(totalTests, "", prefix5, 0, len5);

    // --- Test Case 6 (Partial match) ---
    totalTests++;
    char strs6[4][MAX_WORD_LENGTH] = {"interview", "internet", "internal", "interval"};
    char prefix6[MAX_PREFIX_LENGTH] = "";
    int len6 = longestCommonPrefix(strs6, 4, prefix6);
    passedTests += printTestResult(totalTests, "inter", prefix6, 5, len6);

    // --- Test Case 7 (No match at all) ---
    totalTests++;
    char strs7[3][MAX_WORD_LENGTH] = {"abc", "def", "ghi"};
    char prefix7[MAX_PREFIX_LENGTH] = "";
    int len7 = longestCommonPrefix(strs7, 3, prefix7);
    passedTests += printTestResult(totalTests, "", prefix7, 0, len7);

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}