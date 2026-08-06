class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mn = nums[0], res = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) std::swap(mx, mn);
            mx = std::max(nums[i], mx * nums[i]);
            mn = std::min(nums[i], mn * nums[i]);
            res = std::max(res, mx);
        }
        return res;
    }
};