// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap the 0 to the front (low boundary)
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            // 1 is in the middle, just leave it and move on
            mid++;
        } 
        else { // nums[mid] == 2
            // Swap the 2 to the back (high boundary)
            swap(&nums[mid], &nums[high]);
            high--;
            // Note: We do not increment 'mid' here because the swapped 
            // element from 'high' still needs to be evaluated.
        }
    }
}