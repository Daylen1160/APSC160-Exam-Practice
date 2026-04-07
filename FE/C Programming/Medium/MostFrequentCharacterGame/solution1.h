/**
 * @file solution1.h
 * @brief Most Frequent Character Game Solution
 * @author Aly Khan Nuruddin
 */
#include <stdio.h>    // For standard input/output (printf, scanf)
#include <stdlib.h>   // For random functions (rand, srand)
#include <time.h>     // For time() to seed the generator
#include <string.h>   // For string functions (strlen)

// Define the required length of the random string
#define STRING_LENGTH 20
// Define the size of the alphabet frequency array
#define ALPHABET_SIZE 26 

int main() {
    // Seed the random number generator once at the start.
    srand(time(NULL));
    
    // Declare a character array (string) for the 20 letters plus the null terminator.
    char random_string[STRING_LENGTH + 1]; 
    
    // An array to store the frequency count for each letter 'a' through 'z'.
    // Index 0 stores 'a' count, Index 1 stores 'b' count, and so on.
    int frequency[ALPHABET_SIZE] = {0}; 
    
    int i;
    int max_freq = 0;
    
    // --- 1. Generate Random String and Calculate Frequencies ---
    
    printf("--- Most Frequent Character Game ---\n");
    printf("Generating a random string of %d lowercase letters...\n\n", STRING_LENGTH);
    
    for (i = 0; i < STRING_LENGTH; i++) {
        // Generate a random integer from 0 to 25.
        int rand_val = rand() % ALPHABET_SIZE;
        
        // Convert the integer (0-25) to a lowercase letter ('a' through 'z').
        char random_char = rand_val + 'a';
        random_string[i] = random_char;
        
        // Count the frequency using character arithmetic: random_char - 'a' gives the index (0-25).
        frequency[rand_val]++;
    }

    // Null-terminate the string.
    random_string[STRING_LENGTH] = '\0'; 

    // Display the generated string.
    printf("Generated Sequence: **%s**\n", random_string);

    // --- 2. Determine Maximum Frequency ---
    
    // Iterate through the frequency array to find the highest count.
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > max_freq) {
            max_freq = frequency[i];
        }
    }
    
    // --- 3. Start Guessing Loop ---

    char guess_char;
    int guess_freq;
    int is_correct = 0; // Flag to control the loop (0 = keep guessing, 1 = correct)

    printf("\nTry to guess the most frequent character and its exact count.\n");
    
    do {
        printf("\n------------------------------------\n");
        
        // Prompt for character guess. Note the space before %c to consume leftover newline/whitespace.
        printf("Enter your character guess (a-z): ");
        scanf(" %c", &guess_char); 
        
        // Prompt for frequency guess.
        printf("Enter your frequency count guess: ");
        scanf("%d", &guess_freq);

        // --- Check Guessing Logic ---
        
        int char_index = guess_char - 'a';
        
        // Condition 1: Check if the frequency guess is correct.
        if (guess_freq != max_freq) {
            printf("--> Incorrect! The maximum frequency is NOT %d.\n", guess_freq);
            
        } 
        // Condition 2: Check if the character guess is valid (must be a lowercase letter)
        else if (char_index < 0 || char_index >= ALPHABET_SIZE) {
            printf("--> Incorrect! Please enter a valid lowercase letter (a-z).\n");
        }
        // Condition 3: Check if the guessed character has the maximum frequency.
        else if (frequency[char_index] == max_freq) {
            // Both the frequency and the character are correct.
            is_correct = 1;
            
        } else {
            // Frequency was correct (matched max_freq) but character was wrong.
            // Check the frequency of the guessed character to give a hint.
            printf("--> Incorrect! The character '%c' appears only %d times.\n", 
                   guess_char, frequency[char_index]);
        }
        
    } while (is_correct == 0);

    // --- 4. Success Message ---
    
    printf("\n************************************\n");
    printf("🎉 CORRECT! The character '%c' appears %d times.\n", guess_char, max_freq);
    printf("You Win!\n");
    printf("************************************\n");

    return 0;
}