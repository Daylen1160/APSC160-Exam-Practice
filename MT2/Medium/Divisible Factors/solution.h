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
    FILE* outputFile = fopen(fileName, "w");

    if (outputFile == NULL) return -1;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            fprintf(outputFile, "%d ", i);
        }
    }

    fclose(outputFile);



    int value;
    int index = 0;
    FILE* inputFile = fopen(fileName, "r");

    if (inputFile == NULL) return -1;

    while (fscanf(inputFile, "%d", &value) == 1) {
        if (value % d == 0) {
            output_array[index] = value;
            index++;
        }
    }
    
    fclose(inputFile);
    return index;
}