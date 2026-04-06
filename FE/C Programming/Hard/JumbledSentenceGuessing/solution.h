/**
 * @file solution.h
 * @brief Jumbled Sentence Guessing Solution
 * @author Aly Khan Nuruddin & Daylen Chun
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SENTENCES 4
#define WORDS 5
#define MAX_LEN 200

// ------------------------------------------------------------
// Manually split a sentence into 5 words without strtok()
// ------------------------------------------------------------
void split_into_words(const char *sentence, char words[][50]) {
    int w = 0;      // index of current word
    int c = 0;      // index inside a word

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ') {
            words[w][c++] = sentence[i];  // copy char into word
        } else {
            words[w][c] = '\0';           // terminate current word
            w++;                           // move to next word
            c = 0;                         // reset char index
        }
    }

    words[w][c] = '\0'; // terminate final word
}

// ------------------------------------------------------------
// Shuffle the 5 words using Fisher–Yates algorithm
// ------------------------------------------------------------
void shuffle_words(char words[][50]) {
    for (int i = WORDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp[50];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main() {
    srand(time(NULL));   // seed randomness once

    // Exactly 5-word sentences
    const char sentences[][MAX_LEN] = {
        "the children are playing outside",
        "the cat ate my homework",
        "i am reading a book",
        "dogs love to play fetch"
    };

    // Randomly select a sentence
    int idx = rand() % NUM_SENTENCES;
    const char original_sentence;
    strcpy(original_sentence, sentences[idx]);

    // Split selected sentence into words
    char words[WORDS][50];
    split_into_words(original_sentence, words);

    // Shuffle them
    shuffle_words(words);

    // Display the jumbled sentence
    printf("Jumbled words:\n");
    for (int i = 0; i < WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");

    char guess[MAX_LEN];

    // Loop until user guesses correctly
    while (1) {
        printf("Enter your guess for the original sentence:\n");

        // ---------------------------------------------------------
        // Reads entire line until newline 
        // %199[^\n] → prevents buffer overflow (max 199 chars)
        // Leading space in the format string ignores leftover \n
        // ---------------------------------------------------------
        scanf(" %199[^\n]", guess);

        // Compare guess directly, no newline stripping needed
        if (strcmp(guess, original_sentence) == 0) {
            printf("Correct Guess: \"%s\"\n", original_sentence);
            break;
        } else {
            printf("Incorrect. Try again.\n\n");
        }
    }

    return 0;
}
