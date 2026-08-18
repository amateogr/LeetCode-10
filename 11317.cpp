#include <vector>

class Solution {
private:
    bool hasZero(int x) const noexcept {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }

public:
    std::vector<int> getNoZeroIntegers(int n) const {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};