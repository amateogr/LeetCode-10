class Solution {
private:
    int parseDate(std::string_view s) const noexcept {
        int m = (s[0] - '0') * 10 + (s[1] - '0');
        int d = (s[3] - '0') * 10 + (s[4] - '0');
        constexpr int days_before[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        return days_before[m] + d;
    }

public:
    int countDaysTogether(const std::string& arriveAlice, const std::string& leaveAlice, 
                          const std::string& arriveBob, const std::string& leaveBob) const noexcept {
        int startAlice = parseDate(arriveAlice);
        int endAlice = parseDate(leaveAlice);
        int startBob = parseDate(arriveBob);
        int endBob = parseDate(leaveBob);

        int overlapStart = std::max(startAlice, startBob);
        int overlapEnd = std::min(endAlice, endBob);

        return std::max(0, overlapEnd - overlapStart + 1);
    }
};