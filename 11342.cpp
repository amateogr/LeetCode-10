class Solution {
public:
    int numberOfSteps(int num) {
        if (!num) return 0;
        return 32 - __builtin_clz(num) + __builtin_popcount(num) - 1;
    }
};