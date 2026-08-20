class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int r = n % 7;
        return 7 * w * (w + 1) / 2 + 21 * w + r * (w + 1) + r * (r - 1) / 2;
    }
};