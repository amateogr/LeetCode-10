#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        std::sort(coins.begin(), coins.end());
        std::vector<int> c;
        c.reserve(coins.size());
        
        for (int x : coins) {
            bool ok = true;
            for (int y : c) {
                if (x % y == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) c.push_back(x);
        }

        long long max_val = static_cast<long long>(c[0]) * k;
        std::vector<long long> add, sub;
        add.reserve(1 << (c.size() - 1));
        sub.reserve(1 << (c.size() - 1));

        auto dfs = [&](auto& self, int idx, long long current_lcm, int count) -> void {
            if (idx == c.size()) {
                if (count > 0) {
                    if (count & 1) add.push_back(current_lcm);
                    else sub.push_back(current_lcm);
                }
                return;
            }
            
            self(self, idx + 1, current_lcm, count);
            
            long long next_lcm = std::lcm(current_lcm, static_cast<long long>(c[idx]));
            if (next_lcm <= max_val) {
                self(self, idx + 1, next_lcm, count + 1);
            }
        };
        
        dfs(dfs, 0, 1, 0);

        long long low = 1, high = max_val;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cnt = 0;
            
            for (long long l : add) cnt += mid / l;
            for (long long l : sub) cnt -= mid / l;

            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};