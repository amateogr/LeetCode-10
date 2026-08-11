class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0, right = 0;
        for (int x : nums) {
            left = max(left, static_cast<long long>(x));
            right += x;
        }

        long long result = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return static_cast<int>(result);
    }

private:
    bool canSplit(const vector<int>& nums, int k, long long max_sum) const {
        int subarrays = 1;
        long long current_sum = 0;
        for (int x : nums) {
            if (current_sum + x > max_sum) {
                subarrays++;
                current_sum = x;
            } else {
                current_sum += x;
            }
        }
        return subarrays <= k;
    }
};