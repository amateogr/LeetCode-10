#include <stdlib.h>

int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int max_ones = -1;
    int best_row = 0;

    for (int i = 0; i < matSize; i++) {
        int count = 0;
        int cols = matColSize[i];
        for (int j = 0; j < cols; j++) {
            count += mat[i][j];
        }
        if (count > max_ones) {
            max_ones = count;
            best_row = i;
        }
    }

    res[0] = best_row;
    res[1] = max_ones;
    return res;
}