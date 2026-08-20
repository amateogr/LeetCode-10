#include <algorithm>

class Solution {
public:
    int minimumSum(int num) {
        int d[4] = {num % 10, (num / 10) % 10, (num / 100) % 10, num / 1000};
        std::sort(d, d + 4);
        return (d[0] + d[1]) * 10 + (d[2] + d[3]);
    }
};