int numSpecial(int** mat, int matSize, int* matColSize) {
    int row_sum[100] = {0};
    int col_sum[100] = {0};

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j]) {
                row_sum[i]++;
                col_sum[j]++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] && row_sum[i] == 1 && col_sum[j] == 1) {
                count++;
            }
        }
    }

    return count;
}