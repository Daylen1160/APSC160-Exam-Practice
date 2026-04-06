/**
 * @file solution.h
 * @brief Is Palindrome Solution
 * @author Daylen Chun
 */

#include <stdbool.h>
#include <string.h>
bool isPalindrome(char word[]);

/**
 * @brief Check if a given word is a palindrome
 * @param[in] word       The input string to check
 * @return true if the word is a palindrome, false otherwise
 */
// Note: My solution uses bool, but you can also use an int with 1 as true and 0 as false
bool isPalindrome(char word[]) {
    bool isPalin = true;
    for (int i = 0; i < strlen(word) / 2; i++) {
        if (word[i] != word[strlen(word) - 1 - i]) {
            isPalin = false;
        }
    }
    return isPalin;
}
