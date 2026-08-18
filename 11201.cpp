#include <numeric>

class Solution {
public:
    long long nthUglyNumber(long long n, long long a, long long b, long long c) {
        long long ab = std::lcm(a, b);
        long long bc = std::lcm(b, c);
        long long ac = std::lcm(a, c);
        long long abc = std::lcm(ab, c);

        long long low = 1;
        long long high = 2000000000LL;
        long long res = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = (mid / a) + (mid / b) + (mid / c) 
                            - (mid / ab) - (mid / bc) - (mid / ac) 
                            + (mid / abc);
            if (count >= n) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};