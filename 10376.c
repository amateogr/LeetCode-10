int wiggleMaxLength(int* nums, int numsSize) {
    int up = 1, down = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }
    return numsSize == 0 ? 0 : (up > down ? up : down);
}