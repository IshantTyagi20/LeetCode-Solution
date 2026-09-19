void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    
    // Pointer to the last position in the expanded nums1 array
    int p = m + n - 1;
    
    // Iterate backwards and place the largest elements at the end
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    
    // If there are still elements left in nums2, copy them over.
    // (If p1 >= 0, they are already in the correct place in nums1).
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}