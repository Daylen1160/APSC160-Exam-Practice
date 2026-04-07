/**
 * @file solution2.h
 * @brief Random Digit String Analysis Solution
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 20
#define MIN_VALUE 0
#define MAX_VALUE 9

int main(void) {
    char search;
    int counter = 0;

    srand(time(NULL));

    char sequence[SEQUENCE_LENGTH + 1];

    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE) + '0';
    }
    sequence[SEQUENCE_LENGTH] = '\0';

    scanf("%c", &search);

    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (search == sequence[i]) counter++;
    }

    printf("Digit %c appears %d times.\n", search, counter);

    return 0;
}