// Change this to either template.c or solution.c to test
#include "solution.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
int main()
{
    printf("Running Container With Max Water Test Cases...\n");
    printf("====================================================\n\n");
    
    int totalTests = 0;
    int passedTests = 0;
    
    // --- Test Case 1 --- //
    totalTests++;
    int nums1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int attempt1 = containerWithMaxWater(nums1, size1);
    int answer1 = 49;
    
    if (attempt1 == answer1) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]\n");
        printf("  Output: %d\n", attempt1);
        printf("  Expected: %d\n\n", answer1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2:--- //
    totalTests++;
    int nums2[] = {1, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int attempt2 = containerWithMaxWater(nums2, size2);
    int answer2 = 1;
    
    if (attempt2 == answer2) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [1, 1]\n");
        printf("  Output: %d\n", attempt2);
        printf("  Expected: %d\n\n", answer2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3: Simple Ascending ---
    totalTests++;
    int nums3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int attempt3 = containerWithMaxWater(nums3, size3);
    int answer3 = 6; // From [3, 5] (index 2, 4) -> min(3,5)*(4-2) = 6
    
    if (attempt3 == answer3) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [1, 2, 3, 4, 5]\n");
        printf("  Output: %d\n", attempt3);
        printf("  Expected: %d\n\n", answer3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4: Simple Descending ---
    totalTests++;
    int nums4[] = {5, 4, 3, 2, 1};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int attempt4 = containerWithMaxWater(nums4, size4);
    int answer4 = 6; // From [5, 3] (index 0, 2) -> min(5,3)*(2-0) = 6
    
    if (attempt4 == answer4) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [5, 4, 3, 2, 1]\n");
        printf("  Output: %d\n", attempt4);
        printf("  Expected: %d\n\n", answer4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5: "U" Shape (tallest on outsides) ---
    totalTests++;
    int nums5[] = {10, 1, 1, 1, 9};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    int attempt5 = containerWithMaxWater(nums5, size5);
    int answer5 = 36; // From [10, 9] (index 0, 4) -> min(10,9)*(4-0) = 36
    
    if (attempt5 == answer5) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [10, 1, 1, 1, 9]\n");
        printf("  Output: %d\n", attempt5);
        printf("  Expected: %d\n\n", answer5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6: "A" Shape (tallest in middle) ---
    totalTests++;
    int nums6[] = {1, 10, 9, 1};
    int size6 = sizeof(nums6) / sizeof(nums6[0]);
    int attempt6 = containerWithMaxWater(nums6, size6);
    int answer6 = 9; // From [10, 9] (index 1, 2) -> min(10,9)*(2-1) = 9
    
    if (attempt6 == answer6) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [1, 10, 9, 1]\n");
        printf("  Output: %d\n", attempt6);
        printf("  Expected: %d\n\n", answer6);
    }
    printf("----------------------------------------\n");

    // --- Test Case 7: All Same Height ---
    totalTests++;
    int nums7[] = {4, 4, 4, 4};
    int size7 = sizeof(nums7) / sizeof(nums7[0]);
    int attempt7 = containerWithMaxWater(nums7, size7);
    int answer7 = 12; // From [4, 4] (index 0, 3) -> min(4,4)*(3-0) = 12
    
    if (attempt7 == answer7) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [4, 4, 4, 4]\n");
        printf("  Output: %d\n", attempt7);
        printf("  Expected: %d\n\n", answer7);
    }
    printf("----------------------------------------\n");

    // --- Test Case 8: Smallest array (n=2) ---
    totalTests++;
    int nums8[] = {7, 8};
    int size8 = sizeof(nums8) / sizeof(nums8[0]);
    int attempt8 = containerWithMaxWater(nums8, size8);
    int answer8 = 7; // From [7, 8] (index 0, 1) -> min(7,8)*(1-0) = 7
    
    if (attempt8 == answer8) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [7, 8]\n");
        printf("  Output: %d\n", attempt8);
        printf("  Expected: %d\n\n", answer8);
    }
    printf("----------------------------------------\n");

    // --- Test Case 9: Single element (n < 2) ---
    totalTests++;
    int nums9[] = {5};
    int size9 = sizeof(nums9) / sizeof(nums9[0]);
    int attempt9 = containerWithMaxWater(nums9, size9);
    int answer9 = 0; // Loop never runs, returns 0
    
    if (attempt9 == answer9) {
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Input: [5]\n");
        printf("  Output: %d\n", attempt9);
        printf("  Expected: %d\n\n", answer9);
    }
    printf("----------------------------------------\n");

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}