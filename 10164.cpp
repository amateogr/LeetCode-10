#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int min_val = nums[0], max_val = nums[0];
        for (int i = 1; i < n; ++i) {
            min_val = std::min(min_val, nums[i]);
            max_val = std::max(max_val, nums[i]);
        }
        
        if (min_val == max_val) return 0;
        
        int gap = std::max(1, (max_val - min_val) / (n - 1));
        int num_buckets = (max_val - min_val) / gap + 1;
        
        std::vector<int> bucket_min(num_buckets, INT_MAX);
        std::vector<int> bucket_max(num_buckets, INT_MIN);
        
        for (int num : nums) {
            int idx = (num - min_val) / gap;
            bucket_min[idx] = std::min(bucket_min[idx], num);
            bucket_max[idx] = std::max(bucket_max[idx], num);
        }
        
        int max_gap = 0;
        int prev = min_val;
        for (int i = 0; i < num_buckets; ++i) {
            if (bucket_min[i] == INT_MAX) continue;
            max_gap = std::max(max_gap, bucket_min[i] - prev);
            prev = bucket_max[i];
        }
        
        return max_gap;
    }
};