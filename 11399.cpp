#include <vector>

class Solution {
public:
    int countLargestGroup(int n) {
        std::vector<int> sum(n + 1, 0);
        int counts[37] = {0};
        int max_size = 0, max_groups = 0;

        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i / 10] + i % 10;
            int s = sum[i];
            counts[s]++;
            if (counts[s] > max_size) {
                max_size = counts[s];
                max_groups = 1;
            } else if (counts[s] == max_size) {
                max_groups++;
            }
        }

        return max_groups;
    }
};