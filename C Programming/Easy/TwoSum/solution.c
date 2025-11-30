#include <stdio.h>

int twoSum(int[], int, int);

/**
 * @param: nums[] - array of ints
 * @param: numsSize - size of nums[]
 * @param: target - the value to add up to
 * @returns: the sum of the indexes in nums that add up to target, otherwise -1 if no possible sums
 * */

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

