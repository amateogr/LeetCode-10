#include <stdbool.h>

bool isFascinating(int n) {
    int mask = 0;
    int nums[3] = {n, 2 * n, 3 * n};
    for (int i = 0; i < 3; i++) {
        int t = nums[i];
        while (t > 0) {
            int d = t % 10;
            if (!d || (mask & (1 << d))) return false;
            mask |= (1 << d);
            t /= 10;
        }
    }
    return mask == 0x3FE;
}