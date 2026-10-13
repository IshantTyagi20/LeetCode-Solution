#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure we always binary search on the smaller array to minimize the search space
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    
    while (low <= high) {
        // Partition index for nums1
        int partitionX = low + (high - low) / 2;
        // Partition index for nums2
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        // Edge cases: if partition is at the extreme ends, use INT_MIN or INT_MAX
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        // Check if we have found the correct partition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // If total length is even, median is average of max of lefts and min of rights
            if ((m + n) % 2 == 0) {
                return ((double)MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
            } 
            // If total length is odd, median is the max of the left elements
            else {
                return (double)MAX(maxLeftX, maxLeftY);
            }
        } 
        // If maxLeftX is too large, move the partition left in nums1
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } 
        // If maxLeftX is too small, move the partition right in nums1
        else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}