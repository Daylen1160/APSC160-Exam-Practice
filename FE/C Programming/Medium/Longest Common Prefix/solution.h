/**
 * @file solution.h
 * @brief Longest Common Prefix Solution
 * @author Daylen Chun
 */

#include <stdbool.h>
#define MAX_WORD_LENGTH 100
int longestCommonPrefix(char strs[][MAX_WORD_LENGTH], int strsLength, char longestPrefix[]);

/**
 * @brief Find the longest common prefix among an array of strings
 * @param[in] strs           Array of strings
 * @param[in] strsLength     The number of strings in the array
 * @param[out] longestPrefix The longest common prefix found
 * @return The length of the longest common prefix
 */
int longestCommonPrefix(char strs[][MAX_WORD_LENGTH], int strsLength, char longestPrefix[]) {
    if (strsLength == 0) {
        longestPrefix[0] = '\0';
        return 0;
    }
    int prefixLength = 0;
    bool mismatchFound = false;
    while (!mismatchFound) {
        char currentChar = strs[0][prefixLength];
        if (currentChar == '\0') {
            break;
        }
        for (int i = 1; i < strsLength; i++) {
            if (strs[i][prefixLength] != currentChar || strs[i][prefixLength] == '\0') {
                mismatchFound = true;
            }
        }
        if (!mismatchFound) {
            longestPrefix[prefixLength] = currentChar;
            prefixLength++;
        }
    }
    longestPrefix[prefixLength] = '\0';
    return prefixLength;
}