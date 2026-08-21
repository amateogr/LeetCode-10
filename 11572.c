int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    for (int i = 0, j = matSize - 1; i < matSize; ++i, --j) {
        sum += mat[i][i];
        if (i != j) {
            sum += mat[i][j];
        }
    }
    return sum;
}