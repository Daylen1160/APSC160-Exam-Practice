#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// HIJACK MACROS
int portable_rand(void);
void fake_srand(unsigned int seed);
#undef rand
#undef srand
#define rand portable_rand
#define srand fake_srand
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution1.h" or "solution2.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;
static const char* expectedSequence = "65451171626570771087";

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    (void)seed;
    next = 123456789;
}

static int countDigitInSequence(char digit) {
    int count = 0;
    for (int i = 0; expectedSequence[i] != '\0'; i++) {
        if (expectedSequence[i] == digit) {
            count++;
        }
    }
    return count;
}

static int writeInputFile(char digit) {
    FILE* finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }

    fprintf(finput, "%c\n", digit);
    fclose(finput);
    return 1;
}

static int captureProgramOutput(char digit, char outputBuffer[], size_t bufferSize) {
    if (!writeInputFile(digit)) {
        return 0;
    }

    if (!freopen("input.txt", "r", stdin)) {
        perror("freopen stdin failed");
        return 0;
    }

    if (!freopen("output.txt", "w", stdout)) {
        perror("freopen stdout failed");
        return 0;
    }

    next = 12345;
    student_main();
    fflush(stdout);

    FILE* foutput = fopen("output.txt", "r");
    if (foutput == NULL) {
        fprintf(stderr, "Failed to read output.txt\n");
        return 0;
    }

    outputBuffer[0] = '\0';
    char chunk[1024];
    while (fgets(chunk, sizeof(chunk), foutput) != NULL) {
        strncat(outputBuffer, chunk, bufferSize - strlen(outputBuffer) - 1);
    }
    fclose(foutput);
    return 1;
}

static int parseDigitAndCount(const char* output, char* reportedDigit, int* reportedCount) {
    const char* digitWord = strstr(output, "Digit");
    if (digitWord == NULL) {
        return 0;
    }

    digitWord += strlen("Digit");
    while (*digitWord != '\0' && !isdigit((unsigned char)*digitWord)) {
        digitWord++;
    }
    if (*digitWord == '\0') {
        return 0;
    }
    *reportedDigit = *digitWord;

    const char* appearsWord = strstr(digitWord, "appears");
    if (appearsWord == NULL) {
        return 0;
    }

    appearsWord += strlen("appears");
    while (*appearsWord != '\0' && !isdigit((unsigned char)*appearsWord) && *appearsWord != '-') {
        appearsWord++;
    }
    if (*appearsWord == '\0') {
        return 0;
    }

    char* endPtr = NULL;
    long parsedValue = strtol(appearsWord, &endPtr, 10);
    if (appearsWord == endPtr) {
        return 0;
    }

    *reportedCount = (int)parsedValue;
    return 1;
}

static int runTestCase(int caseNumber, char searchDigit) {
    char output[4096];
    int expectedCount = countDigitInSequence(searchDigit);

    if (!captureProgramOutput(searchDigit, output, sizeof(output))) {
        fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
        fprintf(stderr, "  Could not capture program output.\n");
        return 0;
    }

    char reportedDigit = '\0';
    int reportedCount = -1;
    int parsed = parseDigitAndCount(output, &reportedDigit, &reportedCount);
    int countMatches = parsed && reportedDigit == searchDigit && reportedCount == expectedCount;

    if (countMatches) {
        fprintf(stderr, "Test Case %d: PASS\n", caseNumber);
        return 1;
    }

    fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
    fprintf(stderr, "  Search digit: %c\n", searchDigit);
    fprintf(stderr, "  Actual output:\n%s\n", output);
    fprintf(stderr, "  Expected count: %d\n", expectedCount);
    if (parsed) {
        fprintf(stderr, "  Reported digit: %c\n", reportedDigit);
        fprintf(stderr, "  Reported count: %d\n", reportedCount);
    } else {
        fprintf(stderr, "  Could not parse reported digit/count.\n");
    }
    return 0;
}

int main(void) {
    fprintf(stderr, "Running Random Digit String Analysis Test Cases...\n");
    fprintf(stderr, "====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    const char testDigits[] = {'0', '1', '3', '5', '7', '8', '9'};
    int testCount = (int)(sizeof(testDigits) / sizeof(testDigits[0]));

    for (int i = 0; i < testCount; i++) {
        totalTests++;
        if (runTestCase(totalTests, testDigits[i])) {
            passedTests++;
        }
        fprintf(stderr, "----------------------------------------\n");
    }

    fprintf(stderr, "\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    fprintf(stderr, "====================================================\n");
    return 0;
}
