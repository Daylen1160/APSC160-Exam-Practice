/**
 * @file solution.h
 * @brief Read and Equalize Solution
 * @author Daylen Chun
 */

#include <stdio.h>
int readAndEqualize(char fileName[], int fileRows, int evenOrOdd);
int calculateMode(int nums[], int numsSize);

/**
 * @brief Read values from file and calculate minimum removals needed for equalization
 * @param[in] fileName   The name of the file to read from
 * @param[in] fileRows   The number of rows in the file
 * @param[in] evenOrOdd  Column selector (even/odd determines which column to read)
 * @return The minimum number of values to remove to equalize the array
 */
int readAndEqualize(char fileName[], int fileRows, int evenOrOdd) {
    FILE* inputFile;
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("ERROR: Could not open file %s\n", fileName);
        return -1;
    }
    int num1;
    int num2;
    int values[fileRows];
    int i = 0;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        if (evenOrOdd % 2 == 0) {
            values[i] = num2;
        }
        else {
            values[i] = num1;
        }
        i++;
    }
    /* Another solution for the while loop above
    if (evenOrOdd % 2 == 0) {
        while (fscanf(inputFile, "%*d %d", &num) == 1) {
            values[i] = num;
            i++;
        }
    }
    else {
        while (fscanf(inputFile, "%d %*d", &num) == 1) {
            values[i] = num;
            i++;
        }
    }
    */
    fclose(inputFile);
    return fileRows - calculateMode(values, fileRows); //or pass in i
}

/**
 * @brief Calculate the mode (most frequent value) in an array
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The frequency of the most common value in the array
 */
int calculateMode(int nums[], int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int mostSeen = 0;
    for (int i = 0; i < numsSize; i++) {
        int currentTimesSeen = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                currentTimesSeen++;
            }
        }
        if (currentTimesSeen > mostSeen) {
            mostSeen = currentTimesSeen;
        }
    }
    return mostSeen;
}