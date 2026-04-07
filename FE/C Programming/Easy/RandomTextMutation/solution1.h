/**
 * @file solution1.h
 * @brief Random Text Mutation Solution
 * @author Aly Khan Nuruddin and Daylen Chun
 */
#include <stdio.h>    // For standard input/output (printf, scanf)
#include <stdlib.h>   // For random functions (rand, srand)
#include <time.h>     // For time() to seed the generator
#include <string.h>   // For string functions (strlen)
#include <ctype.h>    // For character functions (toupper)

// Define the maximum length of the string the program can handle.
// NOTE: We allow up to 50 characters EXCLUDING the null terminator.
// So the array size for a *valid* stored string is 51 (50 chars + '\0').
#define MAX_LENGTH 51

// --- Function Prototypes for Mutations ---
void uppercaseRandom(char *str);
void replaceRandom(char *str);
void swapEnds(char *str);

// --- MAIN FUNCTION ---

int main() {
    // Seed the random number generator once at the start.
    srand(time(NULL));
    
    /* 
     * input_string is sized large so the user may type "as many characters as they desire".
     * We'll validate using strnlen() and only accept the input if it is <= 50 characters.
     */
    char input_string[1001];               // large read buffer to accept long input safely
    int valid = 0;                         // loop control flag

    // --- 1. Get User Input ---
    while (valid == 0) {                   // loop until valid input

        /* Read into the large buffer. Using a width prevents buffer overflow. */
        if (scanf("%1000s", input_string) != 1) {
            printf("Error. reading input.\n");
            return 1;
        }

        /* Use strnlen to measure the actual entered length safely. */
        int len = strnlen(input_string, sizeof(input_string));

        /* If length exceeds allowed (50), report and prompt again. */
        if (len > (MAX_LENGTH - 1)) {
            printf("Error. String exceeds maximum character limit. Please try again.\n");
        } 
        
        /* Input is valid */
        else {
            valid = 1;
        }
    }

    // --- 2. Randomly Select Mutation ---

    // Generate a random number between 0 and 2 (inclusive) to select the mutation type.
    // 0: Uppercase Random
    // 1: Replace Random with '*'
    // 2: Swap First and Last
    int mutation_choice = rand() % 3;
        
    // --- 3. Apply Selected Mutation ---

    if (mutation_choice == 0) {
        uppercaseRandom(input_string);
        
    } else if (mutation_choice == 1) {
        replaceRandom(input_string);
        
    } else {
        swapEnds(input_string);
        
    }

    // --- 4. Print Result ---
    
    printf("%s\n", input_string);

    return 0;
}

// --- MUTATION IMPLEMENTATIONS ---

/**
 * Mutation 1: Finds a random index and converts the character there to uppercase.
 */
void uppercaseRandom(char *str) {
    int length = strlen(str);
    
    // Choose a random index within the bounds of the string.
    int random_index = rand() % length;
    
    // Use toupper() to convert the character at that index.
    // toupper() is safe even if the character is already uppercase or non-alphabetic.
    str[random_index] = toupper(str[random_index]);
}

/**
 * Mutation 2: Finds a random index and replaces the character with the '*' symbol.
 */
void replaceRandom(char *str) {
    int length = strlen(str);
    
    // Choose a random index within the bounds of the string.
    int random_index = rand() % length;
    
    // Replace the character at the chosen index with '*'.
    str[random_index] = '*';
}

/**
 * Mutation 3: Swaps the character at the beginning (index 0) with the character 
 * at the end (last index).
 */
void swapEnds(char *str) {
    int length = strlen(str);
    // The index of the last character is length - 1.
    int last_index = length - 1; 
    
    // Standard swap using a temporary variable.
    char temp = str[0];
    str[0] = str[last_index];
    str[last_index] = temp;
}