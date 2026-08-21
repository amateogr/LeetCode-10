bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int row_seen[101] = {0};
    int col_seen[101] = {0};

    for (int i = 0; i < n; i++) {
        int tag = i + 1;
        for (int j = 0; j < n; j++) {
            int r = matrix[i][j];
            if (row_seen[r] == tag) return false;
            row_seen[r] = tag;

            int c = matrix[j][i];
            if (col_seen[c] == tag) return false;
            col_seen[c] = tag;
        }
    }
    return true;
}