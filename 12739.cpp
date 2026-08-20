class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            distance += 50;
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return distance + mainTank * 10;
    }
};