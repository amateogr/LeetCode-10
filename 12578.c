int splitNum(int num) {
    int cnt[10] = {0};
    int n = 0;
    while (num) {
        cnt[num % 10]++;
        num /= 10;
        n++;
    }
    int ans[2] = {0};
    for (int i = 0, j = 0; i < n; i++) {
        while (!cnt[j]) j++;
        cnt[j]--;
        ans[i & 1] = ans[i & 1] * 10 + j;
    }
    return ans[0] + ans[1];
}