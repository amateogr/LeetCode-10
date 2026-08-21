void duplicateZeros(int* arr, int arrSize) {
    int p = 0;
    int l = arrSize - 1;
    for (int i = 0; i <= l - p; i++) {
        if (arr[i] == 0) {
            if (i == l - p) {
                arr[l] = 0;
                l--;
                break;
            }
            p++;
        }
    }
    for (int i = l - p; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[i + p] = 0;
            p--;
            arr[i + p] = 0;
        } else {
            arr[i + p] = arr[i];
        }
    }
}