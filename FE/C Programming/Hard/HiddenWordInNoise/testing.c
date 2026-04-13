/**
 * @file testing.c
 * @brief Autograder for Hidden Word in Noise
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// HIJACK MACROS
int portable_rand(void);
void fake_srand(unsigned int seed);
time_t fake_time(time_t *tloc);
#undef rand
#undef srand
#undef time
#define rand portable_rand
#define srand fake_srand
#define time fake_time
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution1.h" or "solution2.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;
static time_t fakeTimeValue = 12345;

static const char *WORD_LIST[] = {"tree", "cat", "fly", "book", "sun"};
static const int WORD_LIST_SIZE = 5;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    next = seed;
}

time_t fake_time(time_t *tloc) {
    if (tloc != NULL) {
        *tloc = fakeTimeValue;
    }
    return fakeTimeValue;
}

static const char *predictTargetWord(time_t seed) {
    fake_srand((unsigned int)seed);
    int wordIdx = portable_rand() % WORD_LIST_SIZE;
    return WORD_LIST[wordIdx];
}

static int writeInputFile(const char *inputScript) {
    FILE *finput = fopen("input.txt", "w");
    if (finput == NULL) {
        return 0;
    }
    fprintf(finput, "%s", inputScript);
    fclose(finput);
    return 1;
}

static int captureProgramOutput(time_t seed,
                                const char *inputScript,
                                char outputBuffer[],
                                size_t bufferSize) {
    if (!writeInputFile(inputScript)) {
        return 0;
    }

    if (!freopen("input.txt", "r", stdin)) {
        return 0;
    }
    if (!freopen("output.txt", "w", stdout)) {
        return 0;
    }

    fakeTimeValue = seed;
    student_main();
    fflush(stdout);

    FILE *foutput = fopen("output.txt", "r");
    if (foutput == NULL) {
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

static int extract30LetterSequence(const char *output, char sequenceOut[31]) {
    const char *p = output;

    while (*p) {
        if (!islower((unsigned char)*p)) {
            p++;
            continue;
        }

        int len = 0;
        char temp[64] = "";
        const char *start = p;
        while (*p && islower((unsigned char)*p) && len < 63) {
            temp[len++] = *p;
            p++;
        }

        if (len == 30) {
            temp[30] = '\0';
            strcpy(sequenceOut, temp);
            return 1;
        }

        if (len > 0 && len != 30) {
            p = start + 1;
        }
    }

    return 0;
}

static int containsIgnoreCase(const char *text, const char *needle) {
    size_t nlen = strlen(needle);
    if (nlen == 0) {
        return 1;
    }

    for (size_t i = 0; text[i] != '\0'; i++) {
        size_t j = 0;
        while (needle[j] != '\0' && text[i + j] != '\0' &&
               tolower((unsigned char)text[i + j]) == tolower((unsigned char)needle[j])) {
            j++;
        }
        if (j == nlen) {
            return 1;
        }
    }
    return 0;
}

static int findInsertionIndex(const char *sequence, const char *targetWord) {
    const char *loc = strstr(sequence, targetWord);
    if (loc == NULL) {
        return -1;
    }
    return (int)(loc - sequence);
}

int main(void) {
    fprintf(stderr, "Running Hidden Word in Noise Test Cases...\n");
    fprintf(stderr, "====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    char outputA[4096] = "";
    char outputB[4096] = "";
    char sequenceA[31] = "";
    char sequenceB[31] = "";

    time_t seedA = 12345;
    time_t seedB = 54321;

    const char *targetA = predictTargetWord(seedA);
    const char *targetB = predictTargetWord(seedB);

    char inputA[128];
    char inputB[128];
    snprintf(inputA, sizeof(inputA), "wrong\n%s\n", targetA);
    snprintf(inputB, sizeof(inputB), "wrong\n%s\n", targetB);

    int ranA = captureProgramOutput(seedA, inputA, outputA, sizeof(outputA));
    int ranB = captureProgramOutput(seedB, inputB, outputB, sizeof(outputB));

    int hasSeqA = ranA && extract30LetterSequence(outputA, sequenceA);
    int hasSeqB = ranB && extract30LetterSequence(outputB, sequenceB);

    // --- Test Case 1: 30-letter sequence is printed ---
    totalTests++;
    if (hasSeqA) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  30-letter sequence found: %s\n", sequenceA);
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        fprintf(stderr, "  Could not find a 30-letter lowercase sequence in output.\n");
    }
    fprintf(stderr, "----------------------------------------\n");

    // --- Test Case 2: Guessing mechanism works + final message includes 'guessed' ---
    totalTests++;
    int hasGuessPrompt = ranA && containsIgnoreCase(outputA, "guess");
    int hasGuessedWord = ranA && containsIgnoreCase(outputA, "guessed");
    if (hasGuessPrompt && hasGuessedWord) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Guess interaction detected.\n");
        fprintf(stderr, "  Final message contains the word 'guessed'.\n");
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        if (!hasGuessPrompt) {
            fprintf(stderr, "  Guessing mechanism not detected in output.\n");
        }
        if (!hasGuessedWord) {
            fprintf(stderr, "  Final output does not contain the word 'guessed'.\n");
        }
    }
    fprintf(stderr, "----------------------------------------\n");

    // --- Test Case 3: Random sequence changes with seed ---
    totalTests++;
    int randomSequenceOK = hasSeqA && hasSeqB && strcmp(sequenceA, sequenceB) != 0;
    if (randomSequenceOK) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Different seeds produced different random sequences.\n");
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        fprintf(stderr, "  Random sequence did not vary across different seeds.\n");
    }
    fprintf(stderr, "----------------------------------------\n");

    // --- Test Case 4: Insertion position changes with seed ---
    totalTests++;
    int insertA = hasSeqA ? findInsertionIndex(sequenceA, targetA) : -1;
    int insertB = hasSeqB ? findInsertionIndex(sequenceB, targetB) : -1;
    int randomInsertOK = (insertA >= 0 && insertB >= 0 && insertA != insertB);
    if (randomInsertOK) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Insertion index changed with seed (%d vs %d).\n", insertA, insertB);
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        fprintf(stderr, "  Insertion index did not vary as expected.\n");
        fprintf(stderr, "  Index A: %d, Index B: %d\n", insertA, insertB);
    }
    fprintf(stderr, "----------------------------------------\n");

    fprintf(stderr, "\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    fprintf(stderr, "====================================================\n");
    return 0;
}