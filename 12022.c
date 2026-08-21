#include <stdlib.h>
#include <string.h>

int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (originalSize != m * n) {
        *returnSize = 0;
        return NULL;
    }
    
    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    if (!res || !*returnColumnSizes) {
        free(res);
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = m;
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        res[i] = (int*)malloc(n * sizeof(int));
        memcpy(res[i], &original[i * n], n * sizeof(int));
    }
    
    return res;
}