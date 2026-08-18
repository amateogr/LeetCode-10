class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= limit; ++i) {
            int rem = n - i;
            if (rem < 0) break;
            int start = std::max(0, rem - limit);
            int end = std::min(limit, rem);
            if (start <= end) {
                ans += (end - start + 1);
            }
        }
        return ans;
    }
};