/**
 * @file solution.h
 * @brief Two Sum Solution
 * @author Daylen Chun
 */

#include <stdio.h>
int twoSum(int[], int, int);

/**
 * @brief Find the smallest sum of indices where two values equal target
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @param[in] target     The target sum value
 * @return The sum of indices where nums[i] + nums[j] == target, or -1 if not found
 */
int twoSum (int nums[], int numsSize, int target) {
    int smallestIndexSum = -1;
    for (int i = 0; i < numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                if (smallestIndexSum == -1 || i + j < smallestIndexSum) {
                    smallestIndexSum = i + j;
                }
            }
        }
    }
    return smallestIndexSum;
}