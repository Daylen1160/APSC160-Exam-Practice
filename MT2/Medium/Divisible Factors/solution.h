/**
 * @file solution.h
 * @brief Divisible Factors Solution
 * @author Daylen Chun
 */

#include <stdio.h>

#define fileName "factors.txt"

int divisible_factors(int n, int d, int output_array[]);

/**
 * @brief Find divisible factors of n and write them to a file
 * @param[in] n             Number to find factors of
 * @param[in] d             Divisor
 * @param[out] output_array Array to be filled with divisible factors
 * @modifies Creates a file "factors.txt" with the factors of n
 * @modifies output_array to be filled with divisible factors
 * @return The size of output_array
 */
int divisible_factors(int n, int d, int output_array[]) {
    FILE* inputFile;
    FILE* outputFile;
    outputFile = fopen(fileName, "w");
    int j = 0;
    if (outputFile != NULL) {
        for (int i = 1; i <= n; i++) {
            if (n % i  == 0) {
                fprintf(outputFile, "%d ", i);
                j++;
            }
        }
    }
    fclose(outputFile);
    inputFile = fopen(fileName, "r");
    int num;
    int returnArraySize = 0;
    if (inputFile != NULL) {
        while (fscanf(inputFile, "%d", &num) == 1) {
            if (num % d == 0) {
                output_array[returnArraySize] = num;
                returnArraySize++;
            }
        }
    }
    fclose(inputFile);
    return returnArraySize;
}