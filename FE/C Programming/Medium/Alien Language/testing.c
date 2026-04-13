#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static void computeExpected(const char *orig, char *out, size_t outSize) {
    size_t len = strlen(orig);
    size_t pos = 0;

    for (size_t i = 0; i < len && pos + 1 < outSize; i++) {
        unsigned char c = (unsigned char)orig[i];

        if (isalpha(c)) {
            unsigned char up = (unsigned char)toupper(c);
            out[pos++] = (char)(up - 32);
        } else if (isdigit(c)) {
            out[pos++] = (char)len;
        } else {
            out[pos++] = orig[i];
        }
    }

    out[pos] = '\0';
}

static int writeInputFile(const char *sentence) {
    FILE *finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }

    fprintf(finput, "%s\n", sentence);
    fclose(finput);
    return 1;
}

static int runStudentProgram(const char *sentence) {
    if (!writeInputFile(sentence)) {
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

    student_main();
    fflush(stdout);
    return 1;
}

static int readDecoderLines(char line1[], size_t line1Size,
                            char line2[], size_t line2Size) {
    FILE *f = fopen("decoder.txt", "r");
    if (f == NULL) {
        return 0;
    }

    if (fgets(line1, (int)line1Size, f) == NULL) {
        fclose(f);
        return 0;
    }

    if (fgets(line2, (int)line2Size, f) == NULL) {
        fclose(f);
        return 0;
    }

    fclose(f);

    line1[strcspn(line1, "\r\n")] = '\0';
    line2[strcspn(line2, "\r\n")] = '\0';
    return 1;
}

static int runTestCase(int caseNumber, const char *inputSentence) {
    if (!runStudentProgram(inputSentence)) {
        printf("Test Case %d: FAIL\n", caseNumber);
        printf("  Could not execute student program.\n");
        return 0;
    }

    char original[4096] = "";
    char actualEncoded[4096] = "";
    if (!readDecoderLines(original, sizeof(original), actualEncoded, sizeof(actualEncoded))) {
        printf("Test Case %d: FAIL\n", caseNumber);
        printf("  Could not read two lines from decoder.txt\n");
        return 0;
    }

    char expectedEncoded[4096] = "";
    computeExpected(inputSentence, expectedEncoded, sizeof(expectedEncoded));

    int line1Pass = strcmp(original, inputSentence) == 0;
    int line2Pass = strcmp(actualEncoded, expectedEncoded) == 0;

    if (line1Pass && line2Pass) {
        printf("Test Case %d: PASS\n", caseNumber);
        return 1;
    }

    printf("Test Case %d: FAIL\n", caseNumber);
    if (!line1Pass) {
        printf("  decoder.txt line 1 mismatch\n");
        printf("  Expected: \"%s\"\n", inputSentence);
        printf("  Actual:   \"%s\"\n", original);
    }
    if (!line2Pass) {
        printf("  decoder.txt line 2 mismatch\n");
        printf("  Expected: \"%s\"\n", expectedEncoded);
        printf("  Actual:   \"%s\"\n", actualEncoded);
    }

    return 0;
}

int main(void) {
    printf("Running Alien Language Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    const char *testInputs[] = {
        "APSC160 is the best course in first year engineering!",
        "I scored 95 on my first quiz!",
        "The 2 foxes jump over 13 lazy dogs."
    };
    int testCount = (int)(sizeof(testInputs) / sizeof(testInputs[0]));

    for (int i = 0; i < testCount; i++) {
        totalTests++;
        if (runTestCase(totalTests, testInputs[i])) {
            passedTests++;
        }
        printf("----------------------------------------\n");
    }

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");
    return 0;
}
