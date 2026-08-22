int alternateDigitSum(int n) {
    int digits[10];
    int len = 0;
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }
    int sum = 0;
    int sign = 1;
    for (int i = len - 1; i >= 0; i--) {
        sum += sign * digits[i];
        sign = -sign;
    }
    return sum;
}