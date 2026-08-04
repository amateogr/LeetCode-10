#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long dvd = llabs(dividend);
    long long dvs = llabs(divisor);
    long long quotient = 0;

    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }

    if (negative) {
        quotient = -quotient;
    }

    if (quotient > INT_MAX) {
        return INT_MAX;
    }
    if (quotient < INT_MIN) {
        return INT_MIN;
    }

    return (int)quotient;
}