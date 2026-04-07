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

static void deriveExpectedData(char sequence[21], int freqs[26], int* maxFreq) {
    for (int i = 0; i < 26; i++) {
        freqs[i] = 0;
    }

    next = 12345;
    for (int i = 0; i < 20; i++) {
        sequence[i] = (char)('a' + (portable_rand() % 26));
        freqs[sequence[i] - 'a']++;
    }
    sequence[20] = '\0';

    *maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freqs[i] > *maxFreq) {
            *maxFreq = freqs[i];
        }
    }
}

static void deriveWinningGuess(char* winner, int* maxFreq, bool winners[26], char sequence[21]) {
    int freqs[26];
    deriveExpectedData(sequence, freqs, maxFreq);

    for (int i = 0; i < 26; i++) {
        winners[i] = (freqs[i] == *maxFreq);
    }

    *winner = 'a';
    for (int i = 0; i < 26; i++) {
        if (winners[i]) {
            *winner = (char)('a' + i);
            break;
        }
    }
}

static int captureProgramOutput(const char* inputScript, char outputBuffer[], size_t bufferSize) {
    FILE* finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }
    fprintf(finput, "%s", inputScript);
    fclose(finput);

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
    char chunk[512];
    while (fgets(chunk, sizeof(chunk), foutput) != NULL) {
        strncat(outputBuffer, chunk, bufferSize - strlen(outputBuffer) - 1);
    }
    fclose(foutput);
    return 1;
}

static int countWordCaseInsensitive(const char* text, const char* word) {
    size_t wordLen = strlen(word);
    if (wordLen == 0) {
        return 0;
    }

    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        size_t j = 0;
        while (word[j] != '\0' && text[i + j] != '\0' &&
               tolower((unsigned char)text[i + j]) == tolower((unsigned char)word[j])) {
            j++;
        }
        if (j == wordLen) {
            count++;
        }
    }
    return count;
}

static int extractLowercaseToken(const char* output, size_t tokenLength, char token[]) {
    for (size_t i = 0; output[i] != '\0'; i++) {
        size_t j = 0;
        while (output[i + j] != '\0' && islower((unsigned char)output[i + j]) && j < tokenLength) {
            token[j] = output[i + j];
            j++;
        }

        if (j == tokenLength) {
            token[j] = '\0';
            return 1;
        }
    }
    return 0;
}

static int runTestCase(int caseNumber) {
    char winner;
    int maxFreq;
    bool winners[26];
    char expectedSequence[21];
    deriveWinningGuess(&winner, &maxFreq, winners, expectedSequence);

    char wrongChar = 'a';
    while (wrongChar <= 'z' && winners[wrongChar - 'a']) {
        wrongChar++;
    }
    if (wrongChar > 'z') {
        wrongChar = (winner == 'z') ? 'a' : (char)(winner + 1);
    }

    char inputScript[4096];
    int offset = snprintf(inputScript, sizeof(inputScript),
                          "%c\n%d\n%c\n%d\n%c\n%d\n",
                          winner, maxFreq + 1,
                          wrongChar, maxFreq,
                          winner, maxFreq);

    for (char c = 'a'; c <= 'z' && offset < (int)sizeof(inputScript) - 16; c++) {
        for (int f = 1; f <= 20 && offset < (int)sizeof(inputScript) - 16; f++) {
            offset += snprintf(inputScript + offset, sizeof(inputScript) - (size_t)offset,
                               "%c\n%d\n", c, f);
        }
    }

    char output[4096];
    if (!captureProgramOutput(inputScript, output, sizeof(output))) {
        fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
        fprintf(stderr, "  Could not capture program output.\n");
        return 0;
    }

    char parsedSequence[21];
    int hasSequence = extractLowercaseToken(output, 20, parsedSequence);
    int sequenceMatches = hasSequence && strcmp(parsedSequence, expectedSequence) == 0;
    int incorrectCount = countWordCaseInsensitive(output, "incorrect");
    int hasWin = strstr(output, "You Win!") != NULL;

    if (sequenceMatches && incorrectCount >= 2 && hasWin) {
        fprintf(stderr, "Test Case %d: PASS\n", caseNumber);
        return 1;
    }

    fprintf(stderr, "Test Case %d: FAIL\n", caseNumber);
    fprintf(stderr, "  Expected sequence: %s\n", expectedSequence);
    if (hasSequence) {
        fprintf(stderr, "  Parsed sequence:   %s\n", parsedSequence);
    } else {
        fprintf(stderr, "  Could not parse a 20-letter lowercase sequence from output.\n");
    }
    fprintf(stderr, "  'incorrect' occurrences found: %d (expected at least 2)\n", incorrectCount);
    fprintf(stderr, "  'You Win!' found: %s\n", hasWin ? "yes" : "no");
    fprintf(stderr, "  Actual output:\n%s\n", output);
    return 0;
}

int main(void) {
    fprintf(stderr, "Running Most Frequent Character Game Test Cases...\n");
    fprintf(stderr, "====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    totalTests++;
    if (runTestCase(totalTests)) {
        passedTests++;
    }
    fprintf(stderr, "----------------------------------------\n");

    fprintf(stderr, "\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    fprintf(stderr, "====================================================\n");
    return 0;
}
