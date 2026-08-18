#include <vector>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int count[102] = {0};
        int ans = 0;
        for (int x : nums) {
            ans += count[x]++;
        }
        return ans;
    }
};