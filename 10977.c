#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    if (!res) return NULL;
    
    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1;
    
    while (left <= right) {
        int l_sq = nums[left] * nums[left];
        int r_sq = nums[right] * nums[right];
        if (l_sq > r_sq) {
            res[pos--] = l_sq;
            left++;
        } else {
            res[pos--] = r_sq;
            right--;
        }
    }
    
    return res;
}