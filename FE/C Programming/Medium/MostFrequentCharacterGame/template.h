/**
 * @file template.h
 * @brief Most Frequent Character Game Template
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 20
#define MIN_CHAR 97
#define MAX_CHAR 122
#define NUM_ALPHABET_LETTERS 26

int main(void) {
    srand(time(NULL));

    char sequence[SEQUENCE_LENGTH + 1];
    int frequency[NUM_ALPHABET_LETTERS] = {0};

    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int randChar = rand() % (MAX_CHAR - MIN_CHAR + 1) + MIN_CHAR;

        sequence[i] = randChar;
        frequency[randChar - 97]++;
    }

    printf("%s", sequence);

    char maxFreqLetter;
    int maxFreqLetterCount = 0;

    for (int i = 0; i < NUM_ALPHABET_LETTERS; i++) {
        if (frequency[i] > maxFreqLetterCount) {
            maxFreqLetterCount = frequency[i];
            maxFreqLetter = i + MIN_CHAR;
        }
    }

    char charGuess;
    int frequencyGuess;

    scanf("%c %d", &charGuess, &frequencyGuess);
    while (charGuess != maxFreqLetter || frequencyGuess != maxFreqLetterCount) {
        printf("Incorrect.\n");
        scanf("%c %d", &charGuess, &frequencyGuess);
    }

    printf("You Win!\n");

    return 0;
}