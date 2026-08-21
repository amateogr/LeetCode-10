int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001] = {0};
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            arr1[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            arr1[idx++] = i;
            count[i]--;
        }
    }
    *returnSize = arr1Size;
    return arr1;
}