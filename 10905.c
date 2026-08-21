int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        while (l < r && (nums[l] & 1) == 0) l++;
        while (l < r && (nums[r] & 1) != 0) r--;
        if (l < r) {
            int tmp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = tmp;
        }
    }
    *returnSize = numsSize;
    return nums;
}