class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), half = n >> 1;
        int s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') ++c1;
            else s1 += num[i] - '0';
        }
        for (int i = half; i < n; ++i) {
            if (num[i] == '?') ++c2;
            else s2 += num[i] - '0';
        }
        if ((c1 + c2) & 1) return true;
        return (s1 - s2) != (c2 - c1) * 9 / 2;
    }
};