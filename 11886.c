#include <stdbool.h>

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int n = matSize;
    bool r0 = true, r90 = true, r180 = true, r270 = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (r0 && mat[i][j] != target[i][j]) r0 = false;
            if (r90 && mat[i][j] != target[j][n - 1 - i]) r90 = false;
            if (r180 && mat[i][j] != target[n - 1 - i][n - 1 - j]) r180 = false;
            if (r270 && mat[i][j] != target[n - 1 - j][i]) r270 = false;
            
            if (!r0 && !r90 && !r180 && !r270) {
                return false;
            }
        }
    }
    
    return true;
}