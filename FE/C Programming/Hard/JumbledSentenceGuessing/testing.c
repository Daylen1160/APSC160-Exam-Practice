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
int hijacked_strcmp(const char *a, const char *b);
#undef rand
#undef srand
#undef time
#undef strcmp
#define rand portable_rand
#define srand fake_srand
#define time fake_time
#define strcmp hijacked_strcmp
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution1.h" or "solution2.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main
#undef strcmp

static unsigned long int next = 1;
static time_t fakeTimeValue = 12345;
static int strcmpCalls = 0;
static int forceEqualAfterCalls = 0;
static char lastComparedTarget[256] = "";

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

static int local_strcmp(const char *a, const char *b) {
    while (*a != '\0' && *b != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

int hijacked_strcmp(const char *a, const char *b) {
    strcmpCalls++;

    if (b != NULL && strlen(b) > 0 && strlen(b) < sizeof(lastComparedTarget)) {
        strncpy(lastComparedTarget, b, sizeof(lastComparedTarget) - 1);
        lastComparedTarget[sizeof(lastComparedTarget) - 1] = '\0';
    }

    // Safety guard to prevent infinite loops in broken implementations.
    if (strcmpCalls > 500) {
        return 0;
    }

    if (forceEqualAfterCalls > 0 && strcmpCalls >= forceEqualAfterCalls) {
        return 0;
    }

    if (a == NULL && b == NULL) {
        return 0;
    }
    if (a == NULL) {
        return -1;
    }
    if (b == NULL) {
        return 1;
    }
    return local_strcmp(a, b);
}

static int writeInputFile(const char *content) {
    FILE *finput = fopen("input.txt", "w");
    if (finput == NULL) {
        return 0;
    }
    fprintf(finput, "%s", content);
    fclose(finput);
    return 1;
}

static int runAndCapture(time_t seed, const char *inputScript,
                         int forceEqualAt, char outputBuffer[], size_t bufferSize) {
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
    strcmpCalls = 0;
    forceEqualAfterCalls = forceEqualAt;
    lastComparedTarget[0] = '\0';

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

static int splitWords(const char *text, char words[5][64]) {
    int count = 0;
    size_t i = 0;

    while (text[i] != '\0' && count < 5) {
        while (isspace((unsigned char)text[i])) {
            i++;
        }
        if (text[i] == '\0') {
            break;
        }

        size_t j = 0;
        while (text[i] != '\0' && !isspace((unsigned char)text[i]) && j < 63) {
            words[count][j++] = text[i++];
        }
        words[count][j] = '\0';
        count++;
    }

    return count;
}

static int extractFirstFiveWordLine(const char *output, char lineOut[], size_t outSize) {
    const char *cursor = output;
    char line[512];

    while (*cursor != '\0') {
        size_t i = 0;
        while (cursor[i] != '\0' && cursor[i] != '\n' && i < sizeof(line) - 1) {
            line[i] = cursor[i];
            i++;
        }
        line[i] = '\0';

        if (countWords(line) == 5) {
            strncpy(lineOut, line, outSize - 1);
            lineOut[outSize - 1] = '\0';
            while (strlen(lineOut) > 0 && isspace((unsigned char)lineOut[strlen(lineOut) - 1])) {
                lineOut[strlen(lineOut) - 1] = '\0';
            }
            return 1;
        }

        cursor += i;
        if (*cursor == '\n') {
            cursor++;
        }
    }

    return 0;
}

static int isPermutationAndReordered(const char *targetSentence, const char *scrambleLine) {
    char targetWords[5][64] = {{0}};
    char scrambleWords[5][64] = {{0}};

    int tCount = splitWords(targetSentence, targetWords);
    int sCount = splitWords(scrambleLine, scrambleWords);
    if (tCount != 5 || sCount != 5) {
        return 0;
    }

    bool used[5] = {false, false, false, false, false};
    for (int i = 0; i < 5; i++) {
        bool found = false;
        for (int j = 0; j < 5; j++) {
            if (!used[j] && local_strcmp(targetWords[i], scrambleWords[j]) == 0) {
                used[j] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }

    int sameOrder = 1;
    for (int i = 0; i < 5; i++) {
        if (local_strcmp(targetWords[i], scrambleWords[i]) != 0) {
            sameOrder = 0;
            break;
        }
    }

    return sameOrder ? 0 : 1;
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

int main(void) {
    fprintf(stderr, "Running Jumbled Sentence Guessing Test Cases...\n");
    fprintf(stderr, "====================================================\n\n");

    int totalTests = 0;
    int passedTests = 0;

    // --- Test Case 1: Program defines at least 4 unique 5-word sentences ---
    totalTests++;
    char uniqueTargets[16][256] = {{0}};
    int uniqueCount = 0;
    int allTargetsHaveFiveWords = 1;

    for (time_t seed = 1; seed <= 120 && uniqueCount < 4; seed++) {
        char output[4096] = "";
        if (!runAndCapture(seed, "x\n", 1, output, sizeof(output))) {
            continue;
        }

        if (lastComparedTarget[0] == '\0') {
            continue;
        }

        if (countWords(lastComparedTarget) != 5) {
            allTargetsHaveFiveWords = 0;
        }

        bool seen = false;
        for (int i = 0; i < uniqueCount; i++) {
            if (local_strcmp(uniqueTargets[i], lastComparedTarget) == 0) {
                seen = true;
                break;
            }
        }
        if (!seen && uniqueCount < 16) {
            strncpy(uniqueTargets[uniqueCount], lastComparedTarget, sizeof(uniqueTargets[0]) - 1);
            uniqueTargets[uniqueCount][sizeof(uniqueTargets[0]) - 1] = '\0';
            uniqueCount++;
        }
    }

    if (uniqueCount >= 4 && allTargetsHaveFiveWords) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Unique discovered sentences: %d\n", uniqueCount);
        fprintf(stderr, "  Each discovered sentence has 5 words: yes\n");
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        fprintf(stderr, "  Unique discovered sentences: %d (expected at least 4)\n", uniqueCount);
        fprintf(stderr, "  Each discovered sentence has 5 words: %s\n",
                allTargetsHaveFiveWords ? "yes" : "no");
    }
    fprintf(stderr, "----------------------------------------\n");

    // --- Test Case 2: Scrambled output remains 5 words and is a reordering ---
    totalTests++;
    time_t scrambleSeed = 77;
    char outputScramble[4096] = "";
    int scrambleCaptureOk = runAndCapture(scrambleSeed, "x\n", 1, outputScramble, sizeof(outputScramble));
    char scrambleLine[512] = "";
    int hasScrambleLine = scrambleCaptureOk && extractFirstFiveWordLine(outputScramble, scrambleLine, sizeof(scrambleLine));
    int scrambleIsFiveWords = hasScrambleLine && countWords(scrambleLine) == 5;
    int targetIsFiveWords = (lastComparedTarget[0] != '\0' && countWords(lastComparedTarget) == 5);
    int isReorderedPermutation = hasScrambleLine && targetIsFiveWords &&
                                 isPermutationAndReordered(lastComparedTarget, scrambleLine);

    if (hasScrambleLine && scrambleIsFiveWords && isReorderedPermutation) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Sentence: %s\n", lastComparedTarget);
        fprintf(stderr, "  Scrambled: %s\n", scrambleLine);
        fprintf(stderr, "  Scrambled sentence has 5 words: yes\n");
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        if (!hasScrambleLine) {
            fprintf(stderr, "  Could not find a 5-word scrambled line in output.\n");
        } else {
            fprintf(stderr, "  Sentence: %s\n", lastComparedTarget);
            fprintf(stderr, "  Scrambled: %s\n", scrambleLine);
            fprintf(stderr, "  Scrambled sentence has 5 words: %s\n", scrambleIsFiveWords ? "yes" : "no");
            fprintf(stderr, "  Scramble is a true reordering: %s\n", isReorderedPermutation ? "yes" : "no");
        }
    }
    fprintf(stderr, "----------------------------------------\n");

    // --- Test Case 3: Program ends once the sentence is guessed ---
    totalTests++;
    time_t guessSeed = 88;
    char discoverOutput[4096] = "";
    int discovered = runAndCapture(guessSeed, "wrong\n", 1, discoverOutput, sizeof(discoverOutput)) &&
                     lastComparedTarget[0] != '\0';

    int guessEndsOnCorrect = 0;
    if (discovered) {
        char inputScript[1024];
        snprintf(inputScript, sizeof(inputScript),
                 "definitely wrong\n%s\nthis line should never be used\n", lastComparedTarget);

        char guessOutput[4096] = "";
        int ranGuess = runAndCapture(guessSeed, inputScript, 0, guessOutput, sizeof(guessOutput));
        int hasSuccessMessage = containsIgnoreCase(guessOutput, "correct") ||
                                containsIgnoreCase(guessOutput, "guessed");
        guessEndsOnCorrect = ranGuess && strcmpCalls == 2 && hasSuccessMessage;
    }

    if (guessEndsOnCorrect) {
        passedTests++;
        fprintf(stderr, "Test Case %d: PASS\n", totalTests);
        fprintf(stderr, "  Program stops after correct guess (strcmp calls: %d).\n", strcmpCalls);
    } else {
        fprintf(stderr, "Test Case %d: FAIL\n", totalTests);
        fprintf(stderr, "  Program did not stop immediately after correct guess.\n");
        fprintf(stderr, "  Observed strcmp calls: %d (expected 2).\n", strcmpCalls);
    }
    fprintf(stderr, "----------------------------------------\n");

    fprintf(stderr, "\nSummary: %d/%d test cases passed.\n", passedTests, totalTests);
    fprintf(stderr, "====================================================\n");
    return 0;
}