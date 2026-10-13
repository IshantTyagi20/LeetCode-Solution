int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            // The minimum must be in the right half (excluding mid)
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            // The minimum is in the left half (including mid)
            right = mid;
        } else {
            // nums[mid] == nums[right]
            // We can't be sure which half, but we can safely discard the rightmost element
            right--;
        }
    }
    
    // When left == right, we have found the minimum
    return nums[left];
}