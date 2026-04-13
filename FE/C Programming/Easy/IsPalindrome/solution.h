/**
 * @file solution.h
 * @brief Is Palindrome Solution
 * @author Daylen Chun
 */

#include <string.h>

int isPalindrome(char word[]);

/**
 * @brief Check if a given word is a palindrome
 * @param[in] word       The input string to check
 * @return 1 if the word is a palindrome, 0 otherwise
 */
int isPalindrome(char word[]) {
    int isPalin = 1;
    int wordLength = strlen(word);

    for (int i = 0; i < wordLength / 2; i++) {
        if (word[i] != word[wordLength - 1 - i]) {
            isPalin = 0;
        }
    }
    return isPalin;
}
