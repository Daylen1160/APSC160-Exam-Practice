// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "solution.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>

#define test1File "test1.txt"
#define test2File "test2.txt"
#define test3File "test3.txt"
#define test4File "test4.txt"
#define test5File "test5.txt"
#define test6File "test6.txt"

int main() {
    printf("Running Read and Equalize Test Cases...\n");
    printf("====================================================\n\n");
    
    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1: Example 1 (Even) ---
    totalTests++;
    int attempt1 = readAndEqualize(test1File, 5, 50); // 50 is even
    int answer1 = 3; // Array: [4, 3, 8, 6, 6]. Mode is 6. Remove 3.
    
    if (attempt1 == answer1) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt1);
        printf("  Expected: %d\n\n", answer1);
    }
    printf("----------------------------------------\n");

    // --- Test Case 2: Test 1 (Odd) ---
    totalTests++;
    int attempt2 = readAndEqualize(test1File, 5, 51); // 51 is odd
    int answer2 = 2; // Array: [1, 1, 4, 1, 11]. Mode is 1. Remove 2.
    
    if (attempt2 == answer2) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt2);
        printf("  Expected: %d\n\n", answer2);
    }
    printf("----------------------------------------\n");

    // --- Test Case 3: All Equal ---
    totalTests++;
    int attempt3 = readAndEqualize(test2File, 3, 2); // 2 is even
    int answer3 = 0; // Array: [7, 7, 7]. Mode is 7. Remove 0.
    
    if (attempt3 == answer3) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt3);
        printf("  Expected: %d\n\n", answer3);
    }
    printf("----------------------------------------\n");

    // --- Test Case 4: All Different ---
    totalTests++;
    int attempt4 = readAndEqualize(test3File, 3, 3); // 3 is odd
    int answer4 = 2; // Array: [1, 3, 5]. Mode is 1. Remove 2.
    
    if (attempt4 == answer4) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt4);
        printf("  Expected: %d\n\n", answer4);
    }
    printf("----------------------------------------\n");

    // --- Test Case 5: Tie for Mode ---
    totalTests++;
    int attempt5 = readAndEqualize(test4File, 4, 2); // 2 is even
    int answer5 = 2; // Array: [10, 20, 10, 20]. Mode is 10. Remove 2.
    
    if (attempt5 == answer5) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt5);
        printf("  Expected: %d\n\n", answer5);
    }
    printf("----------------------------------------\n");

    // --- Test Case 6: Single Row ---
    totalTests++;
    int attempt6 = readAndEqualize(test5File, 1, 1); // 1 is odd
    int answer6 = 0; // Array: [99]. Mode is 99. Remove 0.
    
    if (attempt6 == answer6) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt6);
        printf("  Expected: %d\n\n", answer6);
    }
    printf("----------------------------------------\n");
    
    // --- Test Case 7: Empty File ---
    totalTests++;
    int attempt7 = readAndEqualize(test6File, 0, 2); // 2 is even
    int answer7 = 0; // Array: []. Size 0. Returns 0.
    
    if (attempt7 == answer7) { 
        passedTests++;
        printf("Test Case %d: PASS\n", totalTests);
    } else {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Output: %d\n", attempt7);
        printf("  Expected: %d\n\n", answer7);
    }
    printf("----------------------------------------\n");

    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
    
    return 0;
}

//Helper method (if you use these make sure to include the prototype at the top):

/*
int calculateMode(int nums[], int numsSize) { 
    // TODO: Implement this method
}
*/
