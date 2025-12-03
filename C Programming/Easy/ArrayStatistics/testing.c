// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <stdbool.h>
bool areDoublesEqual(double a, double b);

int main() {
    printf("Running Array Statistics Test Cases...\n");
    printf("====================================================\n\n");
    
    int totalTests = 0;
    int passedTests = 0;
    
    // --- Test Cases for calculateSum --- //
    printf("--- Testing calculateSum ---\n");
    
    // Test Case 1: Standard case
    totalTests++;
    int nums1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int attempt1 = calculateSum(nums1, size1);
    int answer1 = 15;
    
    if (attempt1 == answer1) { 
        passedTests++;
        printf("Test Case %d (Sum): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Sum): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt1);
        printf("  Expected: %d\n\n", answer1);
    }
    printf("----------------------------------------\n");

    // Test Case 2: With negatives and zeros
    totalTests++;
    int nums2[] = {10, -5, 0, 2, -1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int attempt2 = calculateSum(nums2, size2);
    int answer2 = 6;
    
    if (attempt2 == answer2) { 
        passedTests++;
        printf("Test Case %d (Sum): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Sum): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt2);
        printf("  Expected: %d\n\n", answer2);
    }
    printf("----------------------------------------\n");

    // Test Case 3: Single element
    totalTests++;
    int nums3[] = {42};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int attempt3 = calculateSum(nums3, size3);
    int answer3 = 42;
    
    if (attempt3 == answer3) { 
        passedTests++;
        printf("Test Case %d (Sum): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Sum): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt3);
        printf("  Expected: %d\n\n", answer3);
    }
    printf("----------------------------------------\n");

    // --- Test Cases for calculateAverage --- //
    printf("\n--- Testing calculateAverage ---\n");
    
    // Test Case 4: Standard case (int result)
    totalTests++;
    int nums4[] = {1, 2, 3};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    double attempt4 = calculateAverage(nums4, size4);
    double answer4 = 2.0;
    
    if (areDoublesEqual(attempt4, answer4)) { 
        passedTests++;
        printf("Test Case %d (Avg): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Avg): FAIL\n", totalTests);
        printf("  Output: %f\n", attempt4);
        printf("  Expected: %f\n\n", answer4);
    }
    printf("----------------------------------------\n");

    // Test Case 5: Decimal result
    totalTests++;
    int nums5[] = {1, 2};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    double attempt5 = calculateAverage(nums5, size5);
    double answer5 = 1.5;
    
    if (areDoublesEqual(attempt5, answer5)) { 
        passedTests++;
        printf("Test Case %d (Avg): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Avg): FAIL\n", totalTests);
        printf("  Output: %f\n", attempt5);
        printf("  Expected: %f\n\n", answer5);
    }
    printf("----------------------------------------\n");
    
    // --- Test Cases for calculateAboveOrEqualsAverage ---
    printf("\n--- Testing calculateAboveOrEqualsAverage ---\n");

    // Test Case 6: Standard case
    totalTests++;
    int nums6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(nums6) / sizeof(nums6[0]);
    int attempt6 = calculateAboveOrEqualsAverage(nums6, size6);
    int answer6 = 3;
    
    if (attempt6 == answer6) { 
        passedTests++;
        printf("Test Case %d (Above Avg): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Above Avg): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt6);
        printf("  Expected: %d\n\n", answer6);
    }
    printf("----------------------------------------\n");

    // Test Case 7: Decimal average
    totalTests++;
    int nums7[] = {1, 2, 5};
    int size7 = sizeof(nums7) / sizeof(nums7[0]);
    int attempt7 = calculateAboveOrEqualsAverage(nums7, size7);
    int answer7 = 1;
    
    if (attempt7 == answer7) { 
        passedTests++;
        printf("Test Case %d (Above Avg): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Above Avg): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt7);
        printf("  Expected: %d\n\n", answer7);
    }
    printf("----------------------------------------\n");

    // Test Case 8: All elements are the same
    totalTests++;
    int nums8[] = {7, 7, 7, 7};
    int size8 = sizeof(nums8) / sizeof(nums8[0]);
    int attempt8 = calculateAboveOrEqualsAverage(nums8, size8);
    int answer8 = 4;
    
    if (attempt8 == answer8) { 
        passedTests++;
        printf("Test Case %d (Above Avg): PASS\n", totalTests);
    } else {
        printf("Test Case %d (Above Avg): FAIL\n", totalTests);
        printf("  Output: %d\n", attempt8);
        printf("  Expected: %d\n\n", answer8);
    }
    printf("----------------------------------------\n");

    // --- Summary --- //
    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}

bool areDoublesEqual(double a, double b) {
    double epsilon = 0.000001;
    return fabs(a - b) < epsilon;
}

