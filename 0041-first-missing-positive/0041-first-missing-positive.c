int firstMissingPositive(int* nums, int numsSize) {
    // Place each number in its target index: nums[i] should be at index nums[i] - 1
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int targetIdx = nums[i] - 1;
            
            // Swap nums[i] and nums[targetIdx]
            int temp = nums[i];
            nums[i] = nums[targetIdx];
            nums[targetIdx] = temp;
        }
    }

    // Find the first position where the value is not i + 1
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If 1 through numsSize are all present
    return numsSize + 1;
}