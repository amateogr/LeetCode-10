#include <stdlib.h>
#include <string.h>

int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    int* perm = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    
    int low = 0;
    int high = n;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            perm[i] = low++;
        } else {
            perm[i] = high--;
        }
    }
    perm[n] = low;
    
    return perm;
}