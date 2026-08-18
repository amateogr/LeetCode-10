#include <vector>
#include <algorithm>

static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int stoneGameVII(std::vector<int>& stones) {
        const int n = stones.size();
        std::vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stones[i];
        }

        std::vector<int> dp(n * n, 0);

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l <= n - len; ++l) {
                int r = l + len - 1;
                int sum1 = pref[r + 1] - pref[l + 1];
                int sum2 = pref[r] - pref[l];
                dp[l * n + r] = std::max(sum1 - dp[(l + 1) * n + r], sum2 - dp[l * n + (r - 1)]);
            }
        }

        return dp[n - 1];
    }
};