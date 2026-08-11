int power(int base, int exp) {
    int res = 1;
    base %= 1337;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % 1337;
        }
        base = (base * base) % 1337;
        exp >>= 1;
    }
    return res;
}

int superPow(int a, int* b, int bSize) {
    int res = 1;
    for (int i = 0; i < bSize; i++) {
        res = (power(res, 10) * power(a, b[i])) % 1337;
    }
    return res;
}