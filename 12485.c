int pivotInteger(int n) {
    int total = n * (n + 1) / 2;
    int l = 1, r = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int left_sum = m * (m + 1) / 2;
        int right_sum = total - left_sum + m;
        if (left_sum == right_sum) return m;
        if (left_sum < right_sum) l = m + 1;
        else r = m - 1;
    }
    return -1;
}