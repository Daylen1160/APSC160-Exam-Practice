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
    // TODO: Implement this method
 int i=0;
 int sum=0;
 //calculating the sum using the for loop.
 for(i=0;i<numsSize;i++){
  sum=sum+nums[i];
 }
 return sum;
}



/**
 * @param nums[] - array of integers
 * @param numsSize - size of nums[]
 * @return the average of integers in nums[]
 */ 
 
double calculateAverage(int nums[], int numsSize) {
    // TODO: Implement this method
 double average;
 double sum=0;
 
 for(int i=0;i<numsSize;i++){
  sum=sum+nums[i];
 }
 average=sum/numsSize;
return average;
}



/**
 * @param nums[] - array of integers
 * @param numsSize - size of nums[]
 * @return the number of elements above or equal to the average of integers in nums[]
 */ 
 
int calculateAboveOrEqualsAverage(int nums[], int numsSize) {
    // TODO: Implement this method
 int count=0;
 double average;
 double sum=0;
 
 for(int i=0;i<numsSize;i++){
  sum=sum+nums[i];
 }
 average=sum/numsSize;
 for(int i=0;i<numsSize;i++){
  if(nums[i]>=average){
   count++;
  }
 }
return count;
}


