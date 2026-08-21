#include <stdlib.h>

static int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int m = matSize;
    int n = *matColSize;
    int* data = (int*)malloc(m * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        data[i] = (low << 8) | i;
    }
    
    qsort(data, m, sizeof(int), compare);
    
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = data[i] & 0xFF;
    }
    
    free(data);
    *returnSize = k;
    return res;
}