char* convertToBase7(int num) {
    if (num == 0) {
        char* res = malloc(2);
        if (!res) return NULL;
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    
    int is_neg = num < 0;
    long long n = is_neg ? -(long long)num : num;
    
    char temp[32];
    int idx = 0;
    
    while (n > 0) {
        temp[idx++] = (n % 7) + '0';
        n /= 7;
    }
    
    if (is_neg) {
        temp[idx++] = '-';
    }
    
    char* res = malloc(idx + 1);
    if (!res) return NULL;
    
    for (int i = 0; i < idx; i++) {
        res[i] = temp[idx - 1 - i];
    }
    res[idx] = '\0';
    
    return res;
}