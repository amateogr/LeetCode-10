#include <stdlib.h>
#include <string.h>

int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    *returnSize = n;
    
    int* ans = (int*)malloc(n * sizeof(int));
    if (!ans) return NULL;
    
    int prev = -10000;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            prev = i;
        }
        ans[i] = i - prev;
    }
    
    prev = 20000;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) {
            prev = i;
        }
        int dist = prev - i;
        if (dist < ans[i]) {
            ans[i] = dist;
        }
    }
    
    return ans;
}