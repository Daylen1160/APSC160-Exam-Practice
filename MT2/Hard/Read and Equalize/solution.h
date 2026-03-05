#include <stdio.h>

int readAndEqualize(char fileName[], int fileRows, int evenOrOdd);
int calculateMode(int nums[], int numsSize); // HELPER METHOD

/**
 * @param: fileName[] - The name of the file, pretend its a string
 * @param: fileRows - The number of rows in the file
 * @param: evenOrOdd - An integer to determine which column to read from
 * @returns: The minimum number of values to remove to ensure the array is equalized
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