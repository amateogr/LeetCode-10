#include <stdlib.h>

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < matrixSize; ++i) {
        int min_col = 0;
        int min_val = matrix[i][0];
        
        for (int j = 1; j < matrixColSize[i]; ++j) {
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                min_col = j;
            }
        }
        
        int is_lucky = 1;
        for (int k = 0; k < matrixSize; ++k) {
            if (matrix[k][min_col] > min_val) {
                is_lucky = 0;
                break;
            }
        }
        
        if (is_lucky) {
            res[0] = min_val;
            *returnSize = 1;
            return res;
        }
    }
    
    return res;
}