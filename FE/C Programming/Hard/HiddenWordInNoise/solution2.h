/**
 * @file solution2.h
 * @brief Hidden Word in Noise Template
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 10
#define TOTAL_STRING_LENGTH 30
#define NUM_CHARACTERS_IN_ALPHABET 26
#define START_LOWERCASE_CHARS 97

const char wordList[][MAX_WORD_LENGTH] = {"tree", "cat", "fly", "book", "sun"};
const int wordCount = sizeof(wordList) / sizeof(wordList[0]);

int main(void) {
    srand(time(NULL));

    // Get a random word from wordList
    int targetWordIndex = rand() % wordCount;
    char targetWord[MAX_WORD_LENGTH];
    strcpy(targetWord, wordList[targetWordIndex]);
    int targetWordLength = strlen(targetWord);

    // Choose a random index
    // MAX: TOTAL_STRING_LENGTH - targetWordLength
    // MIN: 0
    int randIndex = rand() % (TOTAL_STRING_LENGTH - targetWordLength + 1);

    // Populate the string
    char sequence[TOTAL_STRING_LENGTH + 1];
    for (int i = 0; i < TOTAL_STRING_LENGTH; i++) {
        // If we are within the range of where we put the target word
        if (i >= randIndex && i < randIndex + targetWordLength) {
            sequence[i] = targetWord[i - randIndex];
        }

        // Generate a random character
        else {
            char randomChar = rand() % NUM_CHARACTERS_IN_ALPHABET + START_LOWERCASE_CHARS;
            sequence[i] = randomChar;
        }
    }
    sequence[TOTAL_STRING_LENGTH] = '\0';

    // Guessing game
    char guess[MAX_WORD_LENGTH];
    printf("%s", sequence);

    do {
        scanf("%s", guess);
    } while (strcmp(guess, targetWord));

    printf("You guessed the word correctly!");
    return 0;
}

