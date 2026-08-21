int findLucky(int* arr, int arrSize) {
    int freq[501] = {0};
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]++;
    }
    for (int i = 500; i >= 1; i--) {
        if (freq[i] == i) {
            return i;
        }
    }
    return -1;
}