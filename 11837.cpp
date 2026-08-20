class Solution {
public:
    int sumBase(int n, int k) {
        int s = 0;
        for (; n > 0; n /= k) s += n % k;
        return s;
    }
};