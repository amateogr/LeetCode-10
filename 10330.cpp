#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0, i = 0, sz = nums.size();
        while (miss <= n) {
            if (i < sz && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++patches;
            }
        }
        return patches;
    }
};