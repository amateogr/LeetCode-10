class Solution {
private:
    inline int computeXor(int x) noexcept {
        if (x < 0) return 0;
        switch (x & 3) {
            case 0: return x;
            case 1: return 1;
            case 2: return x + 1;
            case 3: return 0;
        }
        return 0;
    }

public:
    int xorOperation(int n, int start) noexcept {
        int s = start >> 1;
        int e = n & start & 1;
        int ans = computeXor(s + n - 1) ^ computeXor(s - 1);
        return (ans << 1) | e;
    }
};