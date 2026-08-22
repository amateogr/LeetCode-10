#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 0; i < m; i++) {
        qsort(grid[i], n, sizeof(int), cmp);
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
        int max_val = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] > max_val) {
                max_val = grid[i][j];
            }
        }
        ans += max_val;
    }

    return ans;
}