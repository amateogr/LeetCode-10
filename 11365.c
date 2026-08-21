#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int freq[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        freq[i] += freq[i - 1];
    }
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] == 0 ? 0 : freq[nums[i] - 1];
    }
    return result;
}