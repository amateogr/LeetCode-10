#include <stdlib.h>

static int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int combinationSum4(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    unsigned int* dp = (unsigned int*)calloc(target + 1, sizeof(unsigned int));
    if (!dp) return 0;
    
    dp[0] = 1;
    
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] > i) break;
            dp[i] += dp[i - nums[j]];
        }
    }
    
    int result = (int)dp[target];
    free(dp);
    return result;
}