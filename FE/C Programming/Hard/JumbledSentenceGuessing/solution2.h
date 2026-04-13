/**
 * @file solution2.h
 * @brief Jumbled Sentence Guessing Solution
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SENTENCES 4
#define MAX_SENTENCE_LENGTH 99

#define NUM_WORDS 5
#define MAX_WORD_LENGTH 10

void extractWords(char sentence[], char words[NUM_WORDS][MAX_WORD_LENGTH]);
void scrambleWords(char words[NUM_WORDS][MAX_WORD_LENGTH]);

int main(void) {
    srand(time(NULL));

    // Make 4 sentences, 5 words each
    char sentences[NUM_SENTENCES][MAX_SENTENCE_LENGTH] = {
        "67 is not that funny",
        "Daylen has fallen on rocks",
        "APSC160 is the greatest course",
        "Place Vanier has better food"
    };

    // Get a random sentence
    int randSentence = rand() % NUM_SENTENCES;
    char originalSentence[MAX_SENTENCE_LENGTH];
    strcpy(originalSentence, sentences[randSentence]);

    // Get the words from the sentence
    char words[NUM_WORDS][MAX_WORD_LENGTH];
    extractWords(originalSentence, words);

    // Scramble the sentence
    scrambleWords(words);

    // Print the scrambled sentence
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Start guessing game
    char guess[MAX_SENTENCE_LENGTH];
    do {
        scanf(" %98[^\n]", guess);
    } while (strcmp(guess, originalSentence));

    printf("You guessed correctly!\n");

    return 0;
}

void extractWords(char sentence[], char words[NUM_WORDS][MAX_WORD_LENGTH]) {
    // Get the sentence length
    int sentenceLength = strlen(sentence);

    // Keep track of the index we store in the 2d array words
    int wordIndex = 0;

    // Keep track of the start of the word in the sentence
    int startWordIndex = 0;

    for (int i = 0; i <= sentenceLength; i++) {
        // Once we see a space, we know we just finished a word
        // I handled the last word by doing the first condition since there's no space after it
        if (i == sentenceLength || sentence[i] == ' ') {
            // Get the supposed length of the word
            int wordLength = i - startWordIndex;

            // Add the word to words
            strncpy(words[wordIndex], sentence + startWordIndex, wordLength);
            words[wordIndex][wordLength] = '\0';

            // Increase indicies
            wordIndex++;
            startWordIndex = i + 1;
        }
    }
}

void scrambleWords(char words[NUM_WORDS][MAX_WORD_LENGTH]) {
    for (int i = 0; i < NUM_WORDS; i++) {
        // Temporarily store the current word
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);

        // Get a new word
        int randIndex = rand() % NUM_WORDS;

        // Swap the two words
        strcpy(words[i], words[randIndex]);
        strcpy(words[randIndex], temp);
    }
}