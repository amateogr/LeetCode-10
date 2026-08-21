int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 1;
    while (i < numsSize && j < numsSize) {
        if (!(nums[i] & 1)) {
            i += 2;
        } else if (nums[j] & 1) {
            j += 2;
        } else {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i += 2;
            j += 2;
        }
    }
    *returnSize = numsSize;
    return nums;
}