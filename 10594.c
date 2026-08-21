int cmp(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int findLHS(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int max_len = 0;
    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j < numsSize && nums[j] == nums[i]) {
            j++;
        }
        int next_j = j;
        while (next_j < numsSize && nums[next_j] == nums[i] + 1) {
            next_j++;
        }
        if (next_j > j) {
            int len = next_j - i;
            if (len > max_len) {
                max_len = len;
            }
        }
        i = j;
    }
    return max_len;
}