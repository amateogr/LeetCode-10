#include <vector>

class Solution {
public:
    int subsetXORSum(const std::vector<int>& nums) {
        int mask = 0;
        for (int x : nums) {
            mask |= x;
        }
        return mask << (nums.size() - 1);
    }
};