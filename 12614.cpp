#include <vector>

class Solution {
private:
    bool isPrime(int n) const {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    int diagonalPrime(const std::vector<std::vector<int>>& nums) const {
        int maxPrime = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int v1 = nums[i][i];
            if (v1 > maxPrime && isPrime(v1)) {
                maxPrime = v1;
            }
            int v2 = nums[i][n - 1 - i];
            if (v2 > maxPrime && isPrime(v2)) {
                maxPrime = v2;
            }
        }
        return maxPrime;
    }
};