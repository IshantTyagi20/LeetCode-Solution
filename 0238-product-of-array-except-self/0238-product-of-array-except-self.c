#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Dynamically allocate memory for the result array
    int* answer = (int*)malloc(numsSize * sizeof(int));
    
    // Set the return size to be the same as the input size
    *returnSize = numsSize;
    
    // Step 1: Calculate the product of all elements to the left of each index.
    int left_product = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = left_product;
        left_product *= nums[i];
    }
    
    // Step 2: Calculate the product of all elements to the right of each index.
    // Multiply this with the existing left product in the answer array.
    int right_product = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= right_product;
        right_product *= nums[i];
    }
    
    return answer;
}