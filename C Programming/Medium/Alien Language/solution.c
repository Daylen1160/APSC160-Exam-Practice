#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define FILENAME "decoder.txt"

int main (void) {
    FILE* outFile;
    outFile = fopen(FILENAME, "w");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate:\n");
    scanf("%[^\n]%*c", sentence); //Can also use fgets
    

    char alienSentence[MAX_SENTENCE_LENGTH];
    for (int i = 0; i < strlen(sentence); i++) {
        char ch = sentence[i];
        if (isupper(ch)) {
            alienSentence[i] = ch - 32;
        }

        else if (islower(ch)) {
            alienSentence[i] = ch - 64;
        }

        else if (isdigit(ch)) {
            alienSentence[i] = strlen(sentence);
        }

        else {
            alienSentence[i] = ch;
        }
    }

    alienSentence[strlen(sentence)] = '\0';
    fprintf(outFile, "%s\n", sentence);
    fprintf(outFile, "%s\n", alienSentence);
    fclose(outFile);
    return 0;
}