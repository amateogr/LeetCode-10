int heightChecker(int* heights, int heightsSize) {
    int count[101] = {0};
    for (int i = 0; i < heightsSize; i++) {
        count[heights[i]]++;
    }
    int ans = 0, h = 1;
    for (int i = 0; i < heightsSize; i++) {
        while (!count[h]) h++;
        if (heights[i] != h) ans++;
        count[h]--;
    }
    return ans;
}