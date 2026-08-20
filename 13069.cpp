#include <vector>

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        const size_t n = nums.size();
        if (n <= 2) return nums;

        std::vector<int> arr1, arr2;
        arr1.reserve(n);
        arr2.reserve(n);

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (size_t i = 2; i < n; ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};