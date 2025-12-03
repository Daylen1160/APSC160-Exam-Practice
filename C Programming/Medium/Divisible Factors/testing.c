// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

bool areArraysEqual(int* arr1, int* arr2, int size);
void printArray(const char* title, int* arr, int size);
bool checkFileContent(const char* filename, const char* expectedContent);

int main() {
    printf("Running Divisible Factors Test Cases...\n");
    printf("====================================================\n\n");
    
    int totalTests = 0;
    int passedTests = 0;
    
    // --- Test Case 1: Example 1 --- //
    totalTests++;
    int n1 = 6, d1 = 3;
    int expected1Size = 2;
    int expected1[] = {3, 6};
    const char* expected1File = "1 2 3 6 "; 
    
    int actual1[100]; 

    int actual1Size = divisible_factors(n1, d1, actual1);
    
    bool arrayTest1 = (actual1Size == expected1Size && areArraysEqual(actual1, expected1, expected1Size));
    bool fileTest1 = checkFileContent("factors.txt", expected1File); 
    
    if (arrayTest1 && fileTest1) { 
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n1, d1);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n1, d1);
        if (!arrayTest1) { 
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual1, actual1Size);
            printArray("    Expected: ", expected1, expected1Size);
        }
        if (!fileTest1) {
        }
    }
    
    printf("----------------------------------------\n");

    // --- Test Case 2: Example 2 --- //
    totalTests++;
    int n2 = 30, d2 = 5;
    int expected2Size = 4;
    int expected2[] = {5, 10, 15, 30};
    const char* expected2File = "1 2 3 5 6 10 15 30 "; 
    
    int actual2[100];
    int actual2Size = divisible_factors(n2, d2, actual2);
    
    bool arrayTest2 = (actual2Size == expected2Size && areArraysEqual(actual2, expected2, expected2Size));
    bool fileTest2 = checkFileContent("factors.txt", expected2File); 
    
    if (arrayTest2 && fileTest2) {
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n2, d2);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n2, d2);
        if (!arrayTest2) {
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual2, actual2Size);
            printArray("    Expected: ", expected2, expected2Size);
        }
        if (!fileTest2) {
        }
    }
    printf("----------------------------------------\n");
    
    // --- Test Case 3: No divisible factors --- //
    totalTests++;
    int n3 = 10, d3 = 7;
    int expected3Size = 0;
    const char* expected3File = "1 2 5 10 "; 
    
    int actual3[100];
    int actual3Size = divisible_factors(n3, d3, actual3);
    
    bool arrayTest3 = (actual3Size == expected3Size); 
    bool fileTest3 = checkFileContent("factors.txt", expected3File); 
    
    if (arrayTest3 && fileTest3) { 
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n3, d3);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n3, d3);
        if (!arrayTest3) {
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual3, actual3Size);
            printf("    Expected: []\n"); 
        }
        if (!fileTest3) {
        }
    }
    printf("----------------------------------------\n");

    // --- Test Case 4: All factors divisible (d=1) --- //
    totalTests++;
    int n4 = 10, d4 = 1;
    int expected4Size = 4;
    int expected4[] = {1, 2, 5, 10};
    const char* expected4File = "1 2 5 10 "; 
    
    int actual4[100];
    int actual4Size = divisible_factors(n4, d4, actual4);
    
    bool arrayTest4 = (actual4Size == expected4Size && areArraysEqual(actual4, expected4, expected4Size));
    bool fileTest4 = checkFileContent("factors.txt", expected4File); 
    
    if (arrayTest4 && fileTest4) {
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n4, d4);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n4, d4);
        if (!arrayTest4) {
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual4, actual4Size);
            printArray("    Expected: ", expected4, expected4Size);
        }
        if (!fileTest4) {
        }
    }
    printf("----------------------------------------\n");

    // --- Test Case 5: Prime number --- //
    totalTests++;
    int n5 = 13, d5 = 1;
    int expected5Size = 2;
    int expected5[] = {1, 13};
    const char* expected5File = "1 13 "; 
    
    int actual5[100];
    int actual5Size = divisible_factors(n5, d5, actual5);
    
    bool arrayTest5 = (actual5Size == expected5Size && areArraysEqual(actual5, expected5, expected5Size));
    bool fileTest5 = checkFileContent("factors.txt", expected5File); 
    
    if (arrayTest5 && fileTest5) {
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n5, d5);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n5, d5);
        if (!arrayTest5) {
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual5, actual5Size);
            printArray("    Expected: ", expected5, expected5Size);
        }
        if (!fileTest5) {
        }
    }
    printf("----------------------------------------\n");

    // --- Test Case 6: n=1 --- //
    totalTests++;
    int n6 = 1, d6 = 1;
    int expected6Size = 1;
    int expected6[] = {1};
    const char* expected6File = "1 "; 
    
    int actual6[100];
    int actual6Size = divisible_factors(n6, d6, actual6);
    
    bool arrayTest6 = (actual6Size == expected6Size && areArraysEqual(actual6, expected6, expected6Size));
    bool fileTest6 = checkFileContent("factors.txt", expected6File); 

    if (arrayTest6 && fileTest6) {
        passedTests++;
        printf("Test Case %d (n=%d, d=%d): PASS\n", totalTests, n6, d6);
    } else {
        printf("Test Case %d (n=%d, d=%d): FAIL\n", totalTests, n6, d6);
        if (!arrayTest6) {
            printf("  ARRAY CHECK FAIL:\n");
            printArray("    Actual:   ", actual6, actual6Size);
            printArray("    Expected: ", expected6, expected6Size);
        }
        if (!fileTest6) {
        }
    }
    printf("----------------------------------------\n");
    
    printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
}

bool areArraysEqual(int* arr1, int* arr2, int size) {
    if (size == 0) {
        return true;
    }
    
    if (arr1 == NULL || arr2 == NULL) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false; 
        }
    }
    return true;
}

void printArray(const char* title, int* arr, int size) {
    printf("%s", title);
    if (size == 0) {
        printf("[]\n");
        return;
    }
    printf("[%d", arr[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", arr[i]);
    }
    printf("]\n");
}

bool checkFileContent(const char* filename, const char* expectedContent) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("  FILE CHECK ERROR: Could not open %s for reading.\n", filename);
        return false;
    }

    char fileBuffer[1024];
    size_t bytesRead = fread(fileBuffer, 1, 1023, file);
    fclose(file);
    
    fileBuffer[bytesRead] = '\0';
    
    if (strcmp(fileBuffer, expectedContent) != 0) {
        printf("  FILE CHECK FAIL:\n");
        printf("    File Content: \"%s\"\n", fileBuffer);
        printf("    Expected:     \"%s\"\n", expectedContent);
        return false;
    }
    
    return true;
}