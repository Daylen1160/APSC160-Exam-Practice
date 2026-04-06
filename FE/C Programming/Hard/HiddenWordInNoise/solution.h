/**
 * @file solution.h
 * @brief Hidden Word in Noise Solution
 * @author Daylen Chun
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 50   // max size for user input
#define FINAL_SIZE 30 // final string must be 30 characters

// ------------------------------------------------------------
// Function to generate a random lowercase letter
// ------------------------------------------------------------
char random_letter() {
    return 'a' + (rand() % 26);
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // --------------------------------------------------------
    // 1. WORD LIST — program randomly selects one target word
    // --------------------------------------------------------
    const char *words[] = {"tree", "cat", "fly", "book", "sun"};
    int numWords = sizeof(words) / sizeof(words[0]);
    const char *target = words[rand() % numWords];

    int targetLen = strlen(target);

    // --------------------------------------------------------
    // 2. STRING ASSEMBLY — Build a 30-character string
    // --------------------------------------------------------
    char hiddenString[FINAL_SIZE + 1]; // +1 for '\0'

    // Compute how much random noise we need
    int noiseCount = FINAL_SIZE - targetLen;

    // Pick a random index to insert the word
    int insertIndex = rand() % (noiseCount + 1);

    // Fill the entire string with random noise first
    for (int i = 0; i < FINAL_SIZE; i++) {
        hiddenString[i] = random_letter();
    }

    // Overwrite part of the noise with the target word
    for (int i = 0; i < targetLen; i++) {
        hiddenString[insertIndex + i] = target[i];
    }

    // Null-terminate the string
    hiddenString[FINAL_SIZE] = '\0';

    // --------------------------------------------------------
    // Display the 30-character puzzle string
    // --------------------------------------------------------
    printf("Find the hidden word in this string:\n");
    printf("%s\n\n", hiddenString);

    // --------------------------------------------------------
    // 3. GAME LOOP — Ask repeatedly until correct guess
    // --------------------------------------------------------
    char guess[MAX_LEN];

    while (1) {
        printf("Enter your guess: ");

        // Read a whole word (no spaces)
        scanf(" %49s", guess);

        if (strcmp(guess, target) == 0) {
            printf("Correct Guess: \"%s\"\n", target);
            break;
        } else {
            printf("Incorrect. Try again.\n\n");
        }
    }

    return 0;
}