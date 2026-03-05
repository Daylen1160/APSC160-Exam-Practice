#include <stdio.h>

#define fileName "factors.txt"

int divisible_factors(int n, int d, int output_array[]);

/**
 * @param n - number to find factors of
 * @param d - divisor 
 * @param output_array[] - [out] An array (provided by the caller) to be
 * filled with the divisible factors.
 * @modifies: creates a file "factors.txt" with the factors of n
 * @modifies: output_array[] to be filled with divisible factors
 * @returns: The size of output_array[]
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
