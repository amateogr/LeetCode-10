#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) {
            return {-1, -1};
        }
        auto it2 = std::upper_bound(nums.begin(), nums.end(), target);
        int start = std::distance(nums.begin(), it1);
        int end = std::distance(nums.begin(), it2) - 1;
        return {start, end};
    }
};