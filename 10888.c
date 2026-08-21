#include <stdlib.h>

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < aliceSizesSize; i++) sumA += aliceSizes[i];
    for (int i = 0; i < bobSizesSize; i++) sumB += bobSizes[i];
    
    int diff = (sumA - sumB) / 2;
    
    char bob_has[100005] = {0};
    for (int i = 0; i < bobSizesSize; i++) {
        bob_has[bobSizes[i]] = 1;
    }
    
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < aliceSizesSize; i++) {
        int target = aliceSizes[i] - diff;
        if (target >= 0 && target <= 100000 && bob_has[target]) {
            res[0] = aliceSizes[i];
            res[1] = target;
            return res;
        }
    }
    
    return res;
}