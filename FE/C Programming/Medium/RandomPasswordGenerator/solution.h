/**
 * @file solution.h
 * @brief Random Password Generator Solution
 * @author Aly Khan Nuruddin
 */
#include <stdio.h>    // For printf
#include <stdlib.h>   // For rand, srand, malloc, free
#include <time.h>     // For time()
#include <ctype.h>    // For character checking functions (isupper, islower, isdigit)
#include <string.h>   // For strlen (optional, but good practice)

// --- Constants ---
#define PASSWORD_LENGTH 10
#define NUM_REQUIRED_TYPES 4

// Define the safe symbol set
const char SYMBOLS[] = "!@#$%^&*";
const int SYMBOLS_LENGTH = 8; // Length of the SYMBOLS array

// Function to check if a generated password meets the complexity rules
int isValidPassword(const char *pwd);

// Function to generate a random character of a specified type
char generateRandomChar(int type);

// Function to shuffle the characters in the password string
void shuffleString(char *str, int length);

int main() {
    // Seed the random number generator once
    srand(time(NULL));
    
    // Allocate space for the password string (10 chars + null terminator)
    char password[PASSWORD_LENGTH + 1];
    int i;

    // --- 1. GUARANTEE REQUIRED CHARACTERS (First 4 slots) ---
    
    // Indices 0 to 3 are reserved for the required types to ensure validity
    password[0] = generateRandomChar(0); // Uppercase
    password[1] = generateRandomChar(1); // Lowercase
    password[2] = generateRandomChar(2); // Digit
    password[3] = generateRandomChar(3); // Symbol

    // --- 2. FILL REMAINDER RANDOMLY (Last 6 slots) ---

    // Fill the remaining spots (index 4 to 9) with random types
    for (i = NUM_REQUIRED_TYPES; i < PASSWORD_LENGTH; i++) {
        // Generate a random type (0=Upper, 1=Lower, 2=Digit, 3=Symbol)
        int random_type = rand() % NUM_REQUIRED_TYPES;
        password[i] = generateRandomChar(random_type);
    }
    
    // Null-terminate the string
    password[PASSWORD_LENGTH] = '\0';

    // --- 3. SHUFFLE THE PASSWORD ---
    
    // Shuffle the characters to ensure the required types aren't always at the start
    shuffleString(password, PASSWORD_LENGTH);

    // --- 4. OUTPUT AND VALIDATION ---

    printf("Generated Password: **%s**\n", password);

    // OPTIONAL CHALLENGE: Test the output using the isValidPassword function
    if (isValidPassword(password)) {
        printf("[Self-Test Result]: Password meets complexity rules (Valid).\n");
    } else {
        printf("[Self-Test Result]: ERROR: Password failed complexity check (Invalid).\n");
    }

    return 0;
}

// --- HELPER FUNCTION IMPLEMENTATIONS ---

/**
 * Generates a single random character based on the specified type.
 * Type: 0=Upper, 1=Lower, 2=Digit, 3=Symbol.
 */
 
char generateRandomChar(int type) {
    int range;
    char min_char;
    
    // Use if/else if structure instead of switch
    if (type == 0) { // Uppercase (A-Z)
        min_char = 'A';
        range = 'Z' - 'A' + 1;
        return (rand() % range) + min_char;
        
    } else if (type == 1) { // Lowercase (a-z)
        min_char = 'a';
        range = 'z' - 'a' + 1;
        return (rand() % range) + min_char;
        
    } else if (type == 2) { // Digit (0-9)
        min_char = '0';
        range = '9' - '0' + 1;
        return (rand() % range) + min_char;
        
    } else if (type == 3) { // Symbol (!@#$%^&*)
        // Symbols are chosen randomly from the predefined SYMBOLS array
        return SYMBOLS[rand() % SYMBOLS_LENGTH];
        
    } else {
        // Fallback for an invalid type, use 'X' for debugging visibility
        return 'X'; 
    }
}

/**
 * Implements the shuffle algorithm on the string.
 * This is an efficient way to randomize an array/string.
 */
 
void shuffleString(char *str, int length) {
    for (int i = length - 1; i > 0; i--) {
        // Pick a random index j from 0 to i (inclusive)
        int j = rand() % (i + 1);
        
        // Swap str[i] and str[j]
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/**
 * CHALLENGE FUNCTION: Checks if the password meets all four complexity requirements.
 */
 
int isValidPassword(const char *pwd) {
    // Boolean flags (represented by integers 0 or 1 in C)
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSymbol = 0;

    // Iterate through the string until the null terminator is hit
    for (int i = 0; pwd[i] != '\0'; i++) {
        char c = pwd[i];

        // Use functions from <ctype.h>
        if (isupper(c)) {
            hasUpper = 1;
        } else if (islower(c)) {
            hasLower = 1;
        } else if (isdigit(c)) {
            hasDigit = 1;
        } else {
            // Check if the character is one of the allowed symbols
            for (int j = 0; j < SYMBOLS_LENGTH; j++) {
                if (c == SYMBOLS[j]) {
                    hasSymbol = 1;
                    break; 
                }
            }
        }
    }

    // Return 1 (true) only if ALL flags were set
    return (hasUpper && hasLower && hasDigit && hasSymbol);
}