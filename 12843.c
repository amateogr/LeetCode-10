int countSymmetricIntegers(int low, int high) {
    static int p[10001];
    static int init = 0;
    if (!init) {
        for (int i = 1; i <= 10000; ++i) {
            int c = 0;
            if (i >= 10 && i <= 99) {
                if (i / 10 == i % 10) c = 1;
            } else if (i >= 1000 && i <= 9999) {
                if (i / 1000 + (i / 100) % 10 == (i / 10) % 10 + i % 10) c = 1;
            }
            p[i] = p[i - 1] + c;
        }
        init = 1;
    }
    return p[high] - p[low - 1];
}