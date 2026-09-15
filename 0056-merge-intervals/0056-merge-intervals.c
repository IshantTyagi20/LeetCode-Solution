/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

// Comparator function to sort intervals by their start time
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

#include <stdlib.h>

// Simple comparator to sort by start time
int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 1. Sort the intervals
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // 2. Allocate memory for the maximum possible size
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int count = 0; // Tracks the number of intervals in our result array

    // 3. Iterate and merge
    for (int i = 0; i < intervalsSize; i++) {
        // If it's the first interval, OR there is no overlap
        if (count == 0 || res[count - 1][1] < intervals[i][0]) {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = intervals[i][0];
            res[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        } 
        // If there IS an overlap, just update the end time
        else if (intervals[i][1] > res[count - 1][1]) {
            res[count - 1][1] = intervals[i][1];
        }
    }

    // 4. Set the final return size
    *returnSize = count;
    return res;
}