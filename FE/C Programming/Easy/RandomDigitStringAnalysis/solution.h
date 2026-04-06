/**
 * @file solution.h
 * @brief Random Digit String Analysis Solution
 * @author Aly Khan Nuruddin
 */
#include <stdio.h>    // For standard input/output functions (printf, scanf)
#include <stdlib.h>   // For random functions (rand, srand)
#include <time.h>     // For time() to seed the random number generator
#include <string.h>   // Not strictly needed for this solution, but good practice

// Define the required length of the string
#define STRING_LENGTH 20

int main() {
    // --- 1. Initialization and Setup ---

    // Seed the random number generator using the current time.
    // This makes the sequence different each time the program runs.
    srand(time(NULL));

    // Declare a character array (string) to hold the 20 digits, 
    // plus one extra space for the null terminator ('\0').
    char random_string[STRING_LENGTH + 1]; 
    
    int count = 0;
    char search_digit;
    
    // --- 2. Generate Random Digit String ---
    
    printf("Generating a random string of %d digits...\n", STRING_LENGTH);
    
    for (int i = 0; i < STRING_LENGTH; i++) {
        // Generate a random integer from 0 to 9.
        int rand_val = rand() % 10;
        
        // Convert the integer digit (0-9) to its ASCII character representation ('0'-'9').
        // We add the ASCII value of '0' to the integer digit.
        random_string[i] = rand_val + '0';
    }

    // Properly terminate the string with the null character.
    random_string[STRING_LENGTH] = '\0'; 

    // --- 3. Display and Get User Input ---

    printf("Random sequence: **%s**\n", random_string);
    printf("Enter a single digit (0-9) to search for: ");
    
    // Read a single character from the user. Note: &search_digit is required for scanf.
    // We use %c to read the character directly.
    scanf(" %c", &search_digit); 

    // --- 4. String Analysis (Counting) ---

    // Use a loop to iterate through every character in the string.
    // The loop continues as long as the current character is not the null terminator ('\0').
    for (int i = 0; random_string[i] != '\0'; i++) {
        
        // Use a control structure (if statement) to check for a match.
        if (random_string[i] == search_digit) {
            count++; // Increment the counter if the characters match.
        }
    }
    
    // --- 5. Output Result ---

    printf("\nOutput: Digit **%c** appears **%d** times in the sequence.\n", 
           search_digit, count);
           
    return 0;
}