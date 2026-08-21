#include <string>

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        std::string s = std::to_string(num);
        int count = 0;
        int n = s.size();
        for (int i = 0; i <= n - k; ++i) {
            int val = 0;
            for (int j = 0; j < k; ++j) {
                val = val * 10 + (s[i + j] - '0');
            }
            if (val && num % val == 0) {
                ++count;
            }
        }
        return count;
    }
};