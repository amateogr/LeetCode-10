#include <stdbool.h>

bool checkDivisibility(int n) {
    int t = n, s = 0, p = 1;
    while (t) {
        int d = t % 10;
        s += d;
        p *= d;
        t /= 10;
    }
    int sum_prod = s + p;
    return sum_prod && !(n % sum_prod);
}