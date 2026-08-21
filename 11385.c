#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        int val = arr1[i];
        int low = 0, high = arr2Size;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (arr2[mid] >= val) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int found = 0;
        if (low < arr2Size && abs(arr2[low] - val) <= d) {
            found = 1;
        }
        if (low > 0 && abs(arr2[low - 1] - val) <= d) {
            found = 1;
        }
        if (!found) {
            count++;
        }
    }
    return count;
}