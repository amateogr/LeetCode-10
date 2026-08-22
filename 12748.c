int countBeautifulPairs(int* nums, int numsSize) {
    int f[100], l[100], c = 0;
    for (int i = 0; i < numsSize; i++) {
        l[i] = nums[i] % 10;
        int t = nums[i];
        while (t >= 10) t /= 10;
        f[i] = t;
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int a = f[i], b = l[j];
            while (b != 0) {
                int t = b;
                b = a % b;
                a = t;
            }
            if (a == 1) c++;
        }
    }
    return c;
}