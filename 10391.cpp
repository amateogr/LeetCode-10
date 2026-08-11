#include <vector>
#include <algorithm>
#include <set>
#include <climits>

class Solution {
public:
    bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {
        long long total_area = 0;
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = INT_MIN, max_y = INT_MIN;
        std::set<std::pair<int, int>> corners;

        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            total_area += static_cast<long long>(x2 - x1) * (y2 - y1);

            min_x = std::min(min_x, x1);
            min_y = std::min(min_y, y1);
            max_x = std::max(max_x, x2);
            max_y = std::max(max_y, y2);

            auto update = [&](int x, int y) {
                std::pair<int, int> p{x, y};
                if (corners.count(p)) corners.erase(p);
                else corners.insert(p);
            };

            update(x1, y1);
            update(x1, y2);
            update(x2, y1);
            update(x2, y2);
        }

        if (total_area != static_cast<long long>(max_x - min_x) * (max_y - min_y)) {
            return false;
        }

        return corners.size() == 4 &&
               corners.count({min_x, min_y}) &&
               corners.count({min_x, max_y}) &&
               corners.count({max_x, min_y}) &&
               corners.count({max_x, max_y});
    }
};