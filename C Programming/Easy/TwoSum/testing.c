// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
int main() {
    printf("Running Two Sum (Smallest Index Sum) Test Cases...\n");
    printf("====================================================\n\n");
    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1 ---
    totalTests++;
    int nums1[] = {2, 7, 11, 15};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 9;
    int attempt1 = twoSum(nums1, size1, target1);
    int answer1 = 1; // 0 + 1
    
    if (attempt1 == answer1) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt1);
        printf("  Expected: %d\n\n", answer1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2 ---
    totalTests++;
    int nums2[] = {3, 2, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 6;
    int attempt2 = twoSum(nums2, size2, target2);
    int answer2 = 3; // 1 + 2
    
    if (attempt2 == answer2) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt2);
        printf("  Expected: %d\n\n", answer2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3 ---
    totalTests++;
    int nums3[] = {3, 3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int target3 = 6;
    int attempt3 = twoSum(nums3, size3, target3);
    int answer3 = 1; // 0 + 1
    
    if (attempt3 == answer3) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt3);
        printf("  Expected: %d\n\n", answer3);
    }
    printf("----------------------------------------\n");
    
    // --- Test Case 4 (No Solution) ---
    totalTests++;
    int nums4[] = {1, 2, 3, 4};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int target4 = 10;
    int attempt4 = twoSum(nums4, size4, target4);
    int answer4 = -1;
    
    if (attempt4 == answer4) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt4);
        printf("  Expected: %d\n\n", answer4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5 (Empty Array) ---
    totalTests++;
    int* nums5 = NULL;
    int size5 = 0;
    int target5 = 1;
    int attempt5 = twoSum(nums5, size5, target5);
    int answer5 = -1;
    
    if (attempt5 == answer5) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt5);
        printf("  Expected: %d\n\n", answer5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6 (Negatives) ---
    totalTests++;
    int nums6[] = {-1, -2, 3, 5};
    int size6 = sizeof(nums6) / sizeof(nums6[0]);
    int target6 = 2;
    int attempt6 = twoSum(nums6, size6, target6);
    int answer6 = 2; // 0 + 2
    
    if (attempt6 == answer6) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt6);
        printf("  Expected: %d\n\n", answer6);
    }
    printf("----------------------------------------\n");

    // --- Test Case 7 (Multiple Solutions - Core Test) ---
    totalTests++;
    int nums7[] = {1, 5, 3, 3}; // (0,1)=1+5=6, (2,3)=3+3=6
    int size7 = sizeof(nums7) / sizeof(nums7[0]);
    int target7 = 6;
    int attempt7 = twoSum(nums7, size7, target7);
    int answer7 = 1; // 0+1 is smaller than 2+3
    
    if (attempt7 == answer7) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt7);
        printf("  Expected: %d\n\n", answer7);
    }
    printf("----------------------------------------\n");

    // --- Test Case 8 (Multiple Solutions - Reversed) ---
    totalTests++;
    int nums8[] = {3, 3, 1, 5}; // (0,1)=3+3=6, (2,3)=1+5=6
    int size8 = sizeof(nums8) / sizeof(nums8[0]);
    int target8 = 6;
    int attempt8 = twoSum(nums8, size8, target8);
    int answer8 = 1; // 0+1 is smaller than 2+3
    
    if (attempt8 == answer8) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt8);
        printf("  Expected: %d\n\n", answer8);
    }
    printf("----------------------------------------\n");

    // --- Test Case 9 (Multiple Solutions - Harder) ---
    totalTests++;
    int nums9[] = {5, 1, 9, 0, 5}; // (0,3)=5+0=5, (3,4)=0+5=5
    int size9 = sizeof(nums9) / sizeof(nums9[0]);
    int target9 = 5;
    int attempt9 = twoSum(nums9, size9, target9);
    int answer9 = 3; // 0+3 is smaller than 3+4
    
    if (attempt9 == answer9) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt9);
        printf("  Expected: %d\n\n", answer9);
    }
    printf("----------------------------------------\n");

    // --- Test Case 10 (Zeros) ---
    totalTests++;
    int nums10[] = {0, 4, 3, 0};
    int size10 = sizeof(nums10) / sizeof(nums10[0]);
    int target10 = 0;
    int attempt10 = twoSum(nums10, size10, target10);
    int answer10 = 3; // 0 + 3
    
    if (attempt10 == answer10) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt10);
        printf("  Expected: %d\n\n", answer10);
    }
    printf("----------------------------------------\n");


    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    return 0;
}