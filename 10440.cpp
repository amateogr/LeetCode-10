#include <algorithm>

class Solution {
private:
    long long countSteps(long long n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += std::min(static_cast<long long>(n) + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};