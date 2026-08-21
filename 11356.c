#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* res = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        res[i] = (__builtin_popcount(arr[i]) << 16) | arr[i];
    }
    qsort(res, arrSize, sizeof(int), compare);
    for (int i = 0; i < arrSize; i++) {
        res[i] &= 0xFFFF;
    }
    return res;
}