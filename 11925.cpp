#include <cmath>

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; ++a) {
            int a_sq = a * a;
            for (int b = 1; b <= n; ++b) {
                int c_sq = a_sq + b * b;
                int c = static_cast<int>(std::sqrt(c_sq));
                if (c <= n && c * c == c_sq) {
                    ++count;
                }
            }
        }
        return count;
    }
};