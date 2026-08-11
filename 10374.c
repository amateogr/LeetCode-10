int guess(int num);

int guessNumber(int n) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int res = guess(mid);
        if (!res) return mid;
        res < 0 ? (high = mid - 1) : (low = mid + 1);
    }
    return -1;
}