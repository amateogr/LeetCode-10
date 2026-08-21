int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max = 0;
    for (int i = 0; i < accountsSize; ++i) {
        int sum = 0;
        int* row = accounts[i];
        int cols = accountsColSize[i];
        for (int j = 0; j < cols; ++j) {
            sum += row[j];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}