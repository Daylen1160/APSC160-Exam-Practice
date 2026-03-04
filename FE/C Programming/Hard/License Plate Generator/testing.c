#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

int portable_rand(void);
void fake_srand(unsigned int seed);

// HIJACK MACROS
#undef rand
#undef srand
#define rand portable_rand
#define srand fake_srand

/* ============ DO NOT CHANGE ANYTHING ABOVE  THIS LINE ============ */
// Change this to either "template.h" or "solution.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

static unsigned long int next = 1;
int srand_called = 0;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void portable_srand(unsigned int seed) {
    next = seed;
}

void fake_srand(unsigned int seed) {
    srand_called = 1; // Mark that the student called srand
}

// --- Helper: Check Plate Format ---
bool isValidFormat(char *plate) {
    if (strlen(plate) != 7) return false;
    for (int i = 0; i < 3; i++) {
        if (!isupper(plate[i])) return false;
    }
    if (plate[3] != '-') return false;
    for (int i = 4; i < 7; i++) {
        if (!isdigit(plate[i])) return false;
    }
    return true;
}

// --- Helper: Generate Expected Plates ---
void get_expected_plates(unsigned int seed, char expected[NUMPLATES][8]) {
    portable_srand(seed);
    char letters[NUMPLATES][4];
    char digits[NUMPLATES][4];

    for (int i = 0; i < NUMPLATES; i++) {
        // Replicate logic to match student sequence
        bool unique = false;
        while (!unique) {
            for (int j = 0; j < 3; j++) {
                letters[i][j] = 'A' + portable_rand() % 26;
            }
            letters[i][3] = '\0';
            unique = true;
            for (int k = 0; k < i; k++) {
                if (strcmp(letters[k], letters[i]) == 0) unique = false;
            }
        }
        unique = false;
        while (!unique) {
            for (int j = 0; j < 3; j++) {
                digits[i][j] = '0' + portable_rand() % 10;
            }
            digits[i][3] = '\0';
            unique = true;
            for (int k = 0; k < i; k++) {
                if (strcmp(digits[k], digits[i]) == 0) unique = false;
            }
        }
        sprintf(expected[i], "%s-%s", letters[i], digits[i]);
    }
}


int main() {
    printf("Running License Plate Generator Tests...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // Use constants from template.c
    char actual[NUMPLATES][PLATELENGTH]; 
    char expected[NUMPLATES][8];

    // --- Test Case 1: Mandatory Setup & Format Check ---
    totalTests++;
    portable_srand(12345);
    
    // RESET STATE: Crucial for detecting empty templates
    srand_called = 0; 
    memset(actual, 0, sizeof(actual)); // Fill with nulls

    // Run Student Code
    licensePlateGenerator(actual);

    bool formatPass = true;
    bool uniquePass = true;
    
    // 1. Check Mandatory srand()
    if (srand_called == 0) {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Reason: Missing 'srand(time(NULL))'. You must seed the random generator.\n");
    } 
    else {
        // 2. Validate Format
        for (int i = 0; i < NUMPLATES; i++) {
            actual[i][PLATELENGTH - 1] = '\0';
            
            if (!isValidFormat(actual[i])) {
                formatPass = false;
                printf("  [Error] Plate %d invalid format: '%s'\n", i, actual[i]);
            }
        }

        // 3. Validate Uniqueness
        for (int i = 0; i < NUMPLATES; i++) {
            for (int j = i + 1; j < NUMPLATES; j++) {
                if (strcmp(actual[i], actual[j]) == 0 && strlen(actual[i]) > 0) {
                    uniquePass = false;
                    printf("  [Error] Duplicate plates found: %d and %d\n", i, j);
                }
            }
        }

        if (formatPass && uniquePass) {
            passedTests++;
            printf("Test Case %d: PASS\n", totalTests);
            printf("  Mandatory srand() called? Yes.\n");
            printf("  Format and Uniqueness checks passed.\n");
        } else {
            printf("Test Case %d: FAIL\n", totalTests);
        }
    }
    printf("----------------------------------------\n");

    // --- Test Case 2: Deterministic Output Check ---
    totalTests++;
    unsigned int seed = 999;
    portable_srand(seed);
    get_expected_plates(seed, expected); 
    
    // RESET STATE
    portable_srand(seed); 
    srand_called = 0;
    memset(actual, 0, sizeof(actual));
    
    // Run Student Code
    licensePlateGenerator(actual);

    if (srand_called == 0) {
        printf("Test Case %d: FAIL\n", totalTests);
        printf("  Reason: Missing 'srand(time(NULL))'.\n");
    } else {
        bool exactMatch = true;
        for (int i = 0; i < NUMPLATES; i++) {
            if (strcmp(actual[i], expected[i]) != 0) {
                exactMatch = false;
            }
        }

        if (exactMatch) {
            passedTests++;
            printf("Test Case %d: PASS\n", totalTests);
            printf("  Output matched expected sequence exactly.\n");
        } else {
            printf("Test Case %d: FAIL\n", totalTests);
            printf("  Output did not match expected sequence for seed %d.\n", seed);
            printf("  Expected (First 3): %s, %s, %s\n", expected[0], expected[1], expected[2]);
            printf("  Actual   (First 3): %s, %s, %s\n", actual[0], actual[1], actual[2]);
        }
    }
    printf("----------------------------------------\n");

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");
    return 0;
}