int calculateSum(int nums[], int numsSize);
double calculateAverage(int nums[], int numsSize);
int calculateAboveOrEqualsAverage(int nums[], int numsSize);


/**
 * @param[in] nums - array of integers
 * @param[in] numsSize - size of nums[]
 * @returns the sum of integers in nums[]
 */ 
 
int calculateSum(int nums[], int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    return total;
}



/**
 * @param[in] nums - array of integers
 * @param[in] numsSize - size of nums[]
 * @returns the average of integers in nums[]
 */ 
 
double calculateAverage(int nums[], int numsSize) {
    int total = calculateSum(nums, numsSize);
    return (double) total / numsSize;
}



/**
 * @param[in] nums - array of integers
 * @param[in] numsSize - size of nums[]
 * @returns the number of elements above or equal to the average of integers in nums[]
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
