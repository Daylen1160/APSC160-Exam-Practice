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
#include "solution1.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    (void)seed;
    next = 12345;
}

static int containsErrorCaseInsensitive(const char* text) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (tolower((unsigned char)text[i]) == 'e' &&
            tolower((unsigned char)text[i + 1]) == 'r' &&
            tolower((unsigned char)text[i + 2]) == 'r' &&
            tolower((unsigned char)text[i + 3]) == 'o' &&
            tolower((unsigned char)text[i + 4]) == 'r') {
            return 1;
        }
    }
    return 0;
}

static int writeInputFile(const char* inputText) {
    FILE* finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }

    fprintf(finput, "%s", inputText);
    fclose(finput);
    return 1;
}

static int captureProgramOutput(const char* inputText, char outputBuffer[], size_t bufferSize) {
    if (!writeInputFile(inputText)) {
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

static int isUppercaseMutation(const char* original, const char* mutated) {
    size_t len = strlen(original);
    if (strlen(mutated) != len) {
        return 0;
    }

    int changed = 0;
    for (size_t i = 0; i < len; i++) {
        if (mutated[i] == original[i]) {
            continue;
        }

        if (mutated[i] == (char)toupper((unsigned char)original[i])) {
            changed++;
            continue;
        }

        return 0;
    }
    return changed == 1;
}

static int isReplaceMutation(const char* original, const char* mutated) {
    size_t len = strlen(original);
    if (strlen(mutated) != len) {
        return 0;
    }

    int replaced = 0;
    for (size_t i = 0; i < len; i++) {
        if (mutated[i] == original[i]) {
            continue;
        }

        if (mutated[i] == '*') {
            replaced++;
            continue;
        }

        return 0;
    }
    return replaced == 1;
}

static int isSwapEndsMutation(const char* original, const char* mutated) {
    size_t len = strlen(original);
    if (strlen(mutated) != len) {
        return 0;
    }

    if (len <= 1) {
        return strcmp(original, mutated) == 0;
    }

    if (mutated[0] != original[len - 1] || mutated[len - 1] != original[0]) {
        return 0;
    }

    for (size_t i = 1; i + 1 < len; i++) {
        if (mutated[i] != original[i]) {
            return 0;
        }
    }
    return 1;
}

static int extractMutatedToken(const char* output, size_t tokenLength, char token[]) {
    for (size_t i = 0; output[i] != '\0'; i++) {
        if (isspace((unsigned char)output[i])) {
            continue;
        }

        size_t j = 0;
        while (output[i + j] != '\0' && !isspace((unsigned char)output[i + j]) && j < tokenLength) {
            token[j] = output[i + j];
            j++;
        }
        token[j] = '\0';

        if (j == tokenLength) {
            return 1;
        }
    }

    return 0;
}

static int runTestCase(int caseNumber, const char* inputWord) {
    char inputText[256];
    char output[4096];

    snprintf(inputText, sizeof(inputText), "%s\n", inputWord);

    if (!captureProgramOutput(inputText, output, sizeof(output))) {
        fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
        fprintf(stderr, "  Could not capture program output.\n");
        return 0;
    }

    size_t expectedLen = strlen(inputWord);
    char mutated[128];
    int foundToken = extractMutatedToken(output, expectedLen, mutated);

    int passed = 0;
    if (foundToken) {
        passed = isUppercaseMutation(inputWord, mutated) ||
                 isReplaceMutation(inputWord, mutated) ||
                 isSwapEndsMutation(inputWord, mutated);
    }

    if (passed) {
        fprintf(stderr, "Test Case %d: PASS\n", caseNumber);
        return 1;
    }

    fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
    fprintf(stderr, "  Input word: %s\n", inputWord);
    fprintf(stderr, "  Actual output:\n%s\n", output);
    if (foundToken) {
        fprintf(stderr, "  Parsed candidate token: %s\n", mutated);
    } else {
        fprintf(stderr, "  Could not parse a mutated token of expected length.\n");
    }
    return 0;
}

static int runOverLengthCase(int caseNumber, const char* longWord, const char* fallbackWord) {
    char inputText[2048];
    char output[4096];

    snprintf(inputText, sizeof(inputText), "%s\n%s\n", longWord, fallbackWord);

    if (!captureProgramOutput(inputText, output, sizeof(output))) {
        fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
        fprintf(stderr, "  Could not capture program output.\n");
        return 0;
    }

    int sawError = containsErrorCaseInsensitive(output);
    if (sawError) {
        fprintf(stderr, "Test Case %d: PASS\n", caseNumber);
        return 1;
    }

    fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
    fprintf(stderr, "  Expected output to contain 'error' for >50-char input.\n");
    fprintf(stderr, "  Actual output:\n%s\n", output);
    return 0;
}

int main(void) {
    fprintf(stderr, "Running Random Text Mutation Test Cases...\n");
    fprintf(stderr, "====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    const char* testWords[] = {"hello", "programming", "student", "a"};
    int testCount = (int)(sizeof(testWords) / sizeof(testWords[0]));

    for (int i = 0; i < testCount; i++) {
        totalTests++;
        if (runTestCase(totalTests, testWords[i])) {
            passedTests++;
        }
        fprintf(stderr, "----------------------------------------\n");
    }

    totalTests++;
    if (runOverLengthCase(totalTests,
                          "iamsinglehandedlythebestprogrammingstudentintheentirewideworld",
                          "hello")) {
        passedTests++;
    }
    fprintf(stderr, "----------------------------------------\n");

    fprintf(stderr, "\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    fprintf(stderr, "====================================================\n");
    return 0;
}