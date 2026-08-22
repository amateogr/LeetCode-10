#include <stdlib.h>

int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int m = gridSize;
    int n = gridColSize[0];
    *returnSize = n;

    int* ans = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
        ans[j] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            int len = 0;
            if (val == 0) {
                len = 1;
            } else {
                long long x = val;
                if (x < 0) {
                    len = 1;
                    x = -x;
                }
                while (x > 0) {
                    len++;
                    x /= 10;
                }
            }
            if (len > ans[j]) {
                ans[j] = len;
            }
        }
    }

    return ans;
}