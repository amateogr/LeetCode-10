#include <vector>
#include <unordered_map>

class Solution {
private:
    struct Hash {
        size_t operator()(long long x) const {
            x ^= x >> 30;
            x *= 0xbf58476d1ce4e5b9ULL;
            x ^= x >> 27;
            x *= 0x94d049bb133111ebULL;
            x ^= x >> 31;
            return x;
        }
    };

public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0;
        std::vector<std::unordered_map<long long, int, Hash>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].reserve(i);
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                auto it = dp[j].find(diff);
                int cnt = (it != dp[j].end()) ? it->second : 0;
                ans += cnt;
                dp[i][diff] += cnt + 1;
            }
        }
        return ans;
    }
};