#define NUMPLATES 5
#define PLATELENGTH 8
#define NUMLETTERS 3
#define NUMDIGITS 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

bool checkUniqueLetters(char letters[][NUMLETTERS+1], int currentIndex);
bool checkUniqueDigits(char digits[][NUMDIGITS+1], int currentIndex);

/**
 * Generates 5 unique license plates in the format "LLL-DDD"
 * @param licensePlates A 2D array to store the generated license plates
 * @modifies licensePlates with generated plates
 */
void licensePlateGenerator(char licensePlates[][PLATELENGTH]) {
    char letters[NUMPLATES][NUMLETTERS+1];
    char digits[NUMPLATES][NUMDIGITS+1];

    srand(time(NULL));

    for (int i = 0; i < NUMPLATES; i++) {
        // Generate 3 random uppercase letters
        for (int j = 0; j < NUMLETTERS; j++) {
            letters[i][j] = rand() % (90 - 65 + 1) + 65;
        }
        letters[i][NUMLETTERS] = '\0';
        while (!checkUniqueLetters(letters, i)) {
            for (int j = 0; j < NUMLETTERS; j++) {
                letters[i][j] = rand() % (90 - 65 + 1) + 65;
            }
            letters[i][NUMLETTERS] = '\0';
        }

        // Generate 4 random digits
        for (int j = 0; j < NUMDIGITS; j++) {
            digits[i][j] = rand() % (57 - 48 + 1) + 48;
        }
        digits[i][NUMDIGITS] = '\0';
        while (!checkUniqueDigits(digits, i)) {
            for (int j = 0; j < NUMDIGITS; j++) {
                digits[i][j] = rand() % (57 - 48 + 1) + 48;
            }
            digits[i][NUMDIGITS] = '\0';
        }

        // Using string.h functions
        strcpy(licensePlates[i], letters[i]);
        strcat(licensePlates[i], "-");
        strcat(licensePlates[i], digits[i]);
        // Alternative, cleaner way! than that above
        // sprintf(licensePlates[i], "%s-%s", letters[i], digits[i]);
    }
}

bool checkUniqueLetters(char letters[][NUMLETTERS+1], int currentIndex) {
    int unique = true;
    for (int i = 0; i < currentIndex; i++) {
        if (strcmp(letters[i], letters[currentIndex]) == 0) {
            unique = false;
        }
    }
    return unique;
}

bool checkUniqueDigits(char digits[][NUMDIGITS+1], int currentIndex) {
    int unique = true;
    for (int i = 0; i < currentIndex; i++) {
        if (strcmp(digits[i], digits[currentIndex]) == 0) {
            unique = false;
        }
    }
    return unique;
}