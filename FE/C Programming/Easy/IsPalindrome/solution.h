#include <stdbool.h>
#include <string.h>

bool isPalindrome(char word[]);

/**
 * Checks if a given word is a palindrome.
 * @param word The input string to check.
 * @returns true if the word is a palindrome, false otherwise.
 */
bool isPalindrome(char word[]) {
    bool isPalin = true;
    for (int i = 0; i < strlen(word) / 2; i++) {
        if (word[i] != word[strlen(word) - 1 - i]) {
            isPalin = false;
        }
    }
    return isPalin;
}