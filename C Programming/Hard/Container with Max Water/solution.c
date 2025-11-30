int containerWithMaxWater(int heights[], int heightSize);

/**
 * @param: height - array of heights
 * @param: heightSize - size of the height array
 * @returns: the maximum water that can be contained by two heights
 */ 
int containerWithMaxWater(int height[], int heightSize) {
    //If you want to test a solution, just comment the other one out
    
    /* Two pointers, greedy solution */
    
    // int left = 0;
    // int right = heightSize - 1;
    // int maxArea = 0;
    // int currentArea;

    // while (left < right) {
    //     if (height[left] < height[right]) {
    //         currentArea = height[left] * (right - left);
    //     }
        
    //     else {
    //         currentArea = height[right] * (right - left);
    //     }
        
    //     if (currentArea > maxArea) {
    //         maxArea = currentArea;
    //     }

    //     if (height[left] < height[right]) {
    //         left++;
    //     } else {
    //         right--;
    //     }
    // }
    
    /*Brute force solution */
    
    int maxArea = 0;
    int currentArea;
    for (int i = 0; i < heightSize - 1; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            if (height[i] > height[j]) {
                currentArea = height[j] * (j - i);
            }
            
            else {
                currentArea = height[i] * (j - i);
            }
            
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }
        }
    }

    return maxArea;
}
