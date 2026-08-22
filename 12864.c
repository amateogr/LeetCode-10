char* maximumOddBinaryNumber(char* s) {
    int n = 0, ones = 0;
    while (s[n]) {
        ones += s[n] == '1';
        n++;
    }
    int i = 0;
    for (; i < ones - 1; i++) s[i] = '1';
    for (; i < n - 1; i++) s[i] = '0';
    s[n - 1] = '1';
    return s;
}