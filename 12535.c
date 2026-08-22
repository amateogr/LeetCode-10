int differenceOfSum(int* nums, int numsSize) {
    int elem_sum = 0, digit_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        elem_sum += nums[i];
        for (int t = nums[i]; t > 0; t /= 10) {
            digit_sum += t % 10;
        }
    }
    return elem_sum - digit_sum;
}