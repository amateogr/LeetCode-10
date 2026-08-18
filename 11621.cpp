#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;
        if (r > total || r < 0) return 0;
        std::vector<long long> dp(r + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= total; ++i) {
            for (int j = std::min(i, r); j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[r];
    }
};