#include <vector>

class Solution {
public:
    int averageValue(const std::vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                sum += x;
                ++count;
            }
        }
        return count ? sum / count : 0;
    }
};