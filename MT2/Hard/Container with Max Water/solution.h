/**
 * @file solution.h
 * @brief Container with Max Water Solution
 * @author Daylen Chun
 */

#include <math.h> // Contains fmax and fmin

int containerWithMaxWater(int heights[], int heightSize);
int twoPointersSolution(int height[], int heightSize);
int bruteForceSolution(int height[], int heightSize);

/**
 * @brief Find the maximum water that can be contained between two heights
 * @param[in] heights    Array of height values
 * @param[in] heightSize Size of the heights array
 * @return The maximum water that can be contained by two heights
 */
int containerWithMaxWater(int height[], int heightSize) {
    // SET TO 2 for TWO POINTERS SOLUTION
    // SET TO 1 for BRUTE FORCE SOLUTION
    int choice = 2;
    return (choice == 2) ? twoPointersSolution(height, heightSize) : bruteForceSolution(height, heightSize);
}

int twoPointersSolution(int height[], int heightSize) {
    int maxArea = 0;
    int leftPointer = 0;
    int rightPointer = heightSize - 1;

    while (leftPointer < rightPointer) {
        int lowerColumn = fmin(height[rightPointer], height[leftPointer]);
        int currentArea = lowerColumn * (rightPointer - leftPointer);

        maxArea = fmax(currentArea, maxArea);

        if (lowerColumn == height[leftPointer]) leftPointer++;
        else rightPointer--;
    }
    return maxArea;
}

int bruteForceSolution(int height[], int heightSize) {
    int maxArea = 0;
    for (int i = 0; i < heightSize-1; i++) {
        for (int j = i+1; j < heightSize; j++) {
            int currentArea = fmin(height[i], height[j]) * (j - i);
            if (currentArea > maxArea) maxArea = currentArea;
        }
    }
    return maxArea;
}