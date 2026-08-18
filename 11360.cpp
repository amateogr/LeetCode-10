#include <string>
#include <string_view>
#include <cstdlib>

class Solution {
private:
    inline constexpr bool isLeap(int y) const noexcept {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int toDays(std::string_view d) const noexcept {
        int y = (d[0] - '0') * 1000 + (d[1] - '0') * 100 + (d[2] - '0') * 10 + (d[3] - '0');
        int m = (d[5] - '0') * 10 + (d[6] - '0');
        int day = (d[8] - '0') * 10 + (d[9] - '0');

        int days = day;
        for (int i = 1971; i < y; ++i) {
            days += 365 + isLeap(i);
        }
        
        constexpr int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < m; ++i) {
            days += mdays[i] + (i == 2 && isLeap(y));
        }
        return days;
    }

public:
    int daysBetweenDates(std::string date1, std::string date2) const noexcept {
        return std::abs(toDays(date1) - toDays(date2));
    }
};