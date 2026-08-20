class Solution {
public:
    int countEven(int num) {
        int sum = 0, temp = num;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return (num - (sum & 1)) >> 1;
    }
};