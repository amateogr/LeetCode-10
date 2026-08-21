#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize) {
    int freq[4001] = {0};
    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];
        if ((x % 2 == 0 && freq[x / 2 + 2000] > 0) || freq[x * 2 + 2000] > 0) {
            return true;
        }
        freq[x + 2000]++;
    }
    return false;
}