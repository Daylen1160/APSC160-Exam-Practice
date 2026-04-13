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
// Change this to either "template.h" or "solution.h" to test
#include "template.h"
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

// ========== HELPER VALIDATION FUNCTIONS ==========

static int writeInputFile(void) {
    FILE *finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }

    // Feed several candidate answers so a correct implementation can terminate.
    fprintf(finput, "the children are playing outside\n");
    fprintf(finput, "the cat ate my homework\n");
    fprintf(finput, "i am reading a book\n");
    fprintf(finput, "dogs love to play fetch\n");
    fprintf(finput, "wrong sentence example here\n");
    fclose(finput);
    return 1;
}

static int captureProgramOutput(char outputBuffer[], size_t bufferSize) {
    if (!writeInputFile()) {
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

    FILE *foutput = fopen("output.txt", "r");
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

static int countWords(const char *text) {
    int words = 0;
    bool inWord = false;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (!isspace((unsigned char)text[i])) {
            if (!inWord) {
                words++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return words;
}

static int extractCorrectGuessSentence(const char *output, char sentenceOut[], size_t outSize) {
    const char *anchor = strstr(output, "Correct Guess");
    if (anchor == NULL) {
        return 0;
    }

    const char *colon = strchr(anchor, ':');
    if (colon == NULL) {
        return 0;
    }

    const char *p = colon + 1;
    while (*p == ' ' || *p == '"') {
        p++;
    }

    size_t i = 0;
    while (*p != '\0' && *p != '\n' && *p != '"' && i < outSize - 1) {
        sentenceOut[i++] = *p++;
    }

    while (i > 0 && isspace((unsigned char)sentenceOut[i - 1])) {
        i--;
    }
    sentenceOut[i] = '\0';
    return i > 0;
}

static int hasJumbledOutput(const char *output) {
    return (strstr(output, "Jumbled") != NULL) ||
           (strstr(output, "jumbled") != NULL) ||
           (strstr(output, "words") != NULL);
}

static int hasGuessPrompt(const char *output) {
    return (strstr(output, "Enter your guess") != NULL) ||
           (strstr(output, "guess") != NULL);
}

// ========== TEST CASE RUNNER ==========

typedef struct {
    int caseNumber;
    bool passed;
    bool hasOutput;
    bool hasJumble;
    bool hasPrompt;
    bool hasCorrectGuess;
    bool guessedSentenceHasFiveWords;
    char guessedSentence[256];
} TestResult;

static TestResult runTestCase(int caseNumber) {
    TestResult result;
    result.caseNumber = caseNumber;
    result.passed = false;
    result.hasOutput = false;
    result.hasJumble = false;
    result.hasPrompt = false;
    result.hasCorrectGuess = false;
    result.guessedSentenceHasFiveWords = false;
    strcpy(result.guessedSentence, "");

    char output[4096] = "";
    result.hasOutput = captureProgramOutput(output, sizeof(output));
    if (!result.hasOutput) {
        return result;
    }

    result.hasJumble = hasJumbledOutput(output);
    result.hasPrompt = hasGuessPrompt(output);
    result.hasCorrectGuess = extractCorrectGuessSentence(output, result.guessedSentence,
                                                         sizeof(result.guessedSentence));
    if (result.hasCorrectGuess) {
        result.guessedSentenceHasFiveWords = (countWords(result.guessedSentence) == 5);
    }

    result.passed = result.hasJumble && result.hasPrompt && result.hasCorrectGuess &&
                    result.guessedSentenceHasFiveWords;
    return result;
}

int main(void) {
    printf("Running Jumbled Sentence Guessing Test Cases...\n");
    printf("====================================================\n\n");

    int totalTests = 5;
    int passedTests = 0;

    for (int i = 1; i <= totalTests; i++) {
        TestResult result = runTestCase(i);

        if (result.passed) {
            printf("Test Case %d: PASS\n", result.caseNumber);
            printf("  Jumbled output shown: yes\n");
            printf("  Guess prompt shown: yes\n");
            printf("  Correct Guess found: yes\n");
            printf("  Correct sentence: \"%s\"\n", result.guessedSentence);
            printf("  Sentence has exactly 5 words: yes\n");
            passedTests++;
        } else {
            printf("Test Case %d: FAIL\n", result.caseNumber);

            if (!result.hasOutput) {
                printf("  ERROR: Could not capture program output\n");
            } else if (!result.hasJumble) {
                printf("  ERROR: Missing jumbled words output section\n");
            } else if (!result.hasPrompt) {
                printf("  ERROR: Missing guess prompt\n");
            } else if (!result.hasCorrectGuess) {
                printf("  ERROR: Missing 'Correct Guess' output\n");
            } else if (!result.guessedSentenceHasFiveWords) {
                printf("  ERROR: Correct sentence is not exactly 5 words\n");
                printf("  Parsed sentence: \"%s\"\n", result.guessedSentence);
            }
        }

        printf("----------------------------------------\n");
    }

    printf("\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    printf("====================================================\n");

    return 0;
}