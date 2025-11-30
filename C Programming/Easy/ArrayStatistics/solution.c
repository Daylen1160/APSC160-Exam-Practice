#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int calculateSum(int nums[], int numsSize);
double calculateAverage(int nums[], int numsSize);
int calculateAboveOrEqualsAverage(int nums[], int numsSize);


/**
 * @param nums[] - array of integers
 * @param numsSize - size of nums[]
 * @return the sum of integers in nums[]
 */ 
 
int calculateSum(int nums[], int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    return total;
}



/**
 * @param nums[] - array of integers
 * @param numsSize - size of nums[]
 * @return the average of integers in nums[]
 */ 
 
double calculateAverage(int nums[], int numsSize) {
    int total = calculateSum(nums, numsSize);
    return (double) total / numsSize;
}



/**
 * @param nums[] - array of integers
 * @param numsSize - size of nums[]
 * @return the number of elements above or equal to the average of integers in nums[]
 */ 

int calculateAboveOrEqualsAverage(int nums[], int numsSize) {
    double average = calculateAverage(nums, numsSize);
    int aboveAverage = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= average) {
            aboveAverage++;
        }
    }
    return aboveAverage;
}
