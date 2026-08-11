#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool canCross(const std::vector<int>& stones) {
        const int n = stones.size();
        if (stones[1] != 1) return false;

        std::unordered_map<int, int> stone_indices;
        stone_indices.reserve(n);
        for (int i = 0; i < n; ++i) {
            stone_indices[stones[i]] = i;
        }

        std::vector<std::unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 0; i < n; ++i) {
            for (int k : dp[i]) {
                for (int step = k - 1; step <= k + 1; ++step) {
                    if (step <= 0) continue;
                    auto it = stone_indices.find(stones[i] + step);
                    if (it != stone_indices.end()) {
                        int next_idx = it->second;
                        if (next_idx == n - 1) return true;
                        dp[next_idx].insert(step);
                    }
                }
            }
        }

        return false;
    }
};