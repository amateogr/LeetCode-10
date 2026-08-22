#include <stdlib.h>

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int sz = n - 2;
    *returnSize = sz;
    *returnColumnSizes = (int*)malloc(sz * sizeof(int));
    int** res = (int**)malloc(sz * sizeof(int*));
    for (int i = 0; i < sz; i++) {
        (*returnColumnSizes)[i] = sz;
        res[i] = (int*)malloc(sz * sizeof(int));
        for (int j = 0; j < sz; j++) {
            int mx = 0;
            for (int r = i; r <= i + 2; r++) {
                for (int c = j; c <= j + 2; c++) {
                    if (grid[r][c] > mx) {
                        mx = grid[r][c];
                    }
                }
            }
            res[i][j] = mx;
        }
    }
    return res;
}