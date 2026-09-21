#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3-way partition modifies pointers to return the bounds of the "equal" section
void partition3(int* nums, int left, int right, int* less, int* greater) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[pivotIndex];
    
    int l = left;
    int curr = left;
    int r = right;
    
    while (curr <= r) {
        if (nums[curr] < pivot) {
            swap(&nums[curr], &nums[l]);
            l++;
            curr++;
        } else if (nums[curr] > pivot) {
            swap(&nums[curr], &nums[r]);
            r--;
        } else {
            curr++;
        }
    }
    
    *less = l;
    *greater = r;
}

int quickselect3way(int* nums, int left, int right, int k_smallest) {
    if (left == right) {
        return nums[left];
    }
    
    int less_bound, greater_bound;
    partition3(nums, left, right, &less_bound, &greater_bound);
    
    // If target is within the block of elements equal to the pivot, we found it
    if (k_smallest >= less_bound && k_smallest <= greater_bound) {
        return nums[less_bound];
    } 
    // If target is in the strictly smaller section
    else if (k_smallest < less_bound) {
        return quickselect3way(nums, left, less_bound - 1, k_smallest);
    } 
    // If target is in the strictly greater section
    else {
        return quickselect3way(nums, greater_bound + 1, right, k_smallest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // The k-th largest is the (numsSize - k)-th smallest element
    return quickselect3way(nums, 0, numsSize - 1, numsSize - k);
}