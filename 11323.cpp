class Solution {
public:
    int maximum69Number(int num) {
        int t = num, p = 1, l = 0;
        while (t > 0) {
            if (t % 10 == 6) l = p;
            t /= 10;
            p *= 10;
        }
        return num + 3 * l;
    }
};