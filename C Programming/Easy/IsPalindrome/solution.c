#include <stdbool.h>
#include <string.h>

/**
 * Checks if a given word is a palindrome.
 * @param word The input string to check.
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