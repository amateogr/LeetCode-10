class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int count[46] = {0};
        int maxCount = 0;

        for (int i = lowLimit; i <= highLimit; ++i) {
            int sum = 0;
            int temp = i;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            maxCount = std::max(maxCount, ++count[sum]);
        }

        return maxCount;
    }
};