#include <stdlib.h>
#include <string.h>

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    int* target = malloc(numsSize * sizeof(int));
    if (!target) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; i++) {
        int pos = index[i];
        if (pos < i) {
            memmove(target + pos + 1, target + pos, (i - pos) * sizeof(int));
        }
        target[pos] = nums[i];
    }
    
    return target;
}