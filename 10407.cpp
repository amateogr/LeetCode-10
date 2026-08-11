#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        std::priority_queue<std::tuple<int, int, int>, 
                            std::vector<std::tuple<int, int, int>>, 
                            std::greater<std::tuple<int, int, int>>> pq;
        std::vector<bool> visited(m * n, false);

        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i * n] = true;
            visited[i * n + n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[m - 1][j], m - 1, j);
            visited[j] = true;
            visited[(m - 1) * n + j] = true;
        }

        int water = 0;
        constexpr int dr[] = {-1, 0, 1, 0};
        constexpr int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; ++i) {
                const int nr = r + dr[i];
                const int nc = c + dc[i];
                const int idx = nr * n + nc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[idx]) {
                    visited[idx] = true;
                    if (heightMap[nr][nc] < h) {
                        water += h - heightMap[nr][nc];
                        pq.emplace(h, nr, nc);
                    } else {
                        pq.emplace(heightMap[nr][nc], nr, nc);
                    }
                }
            }
        }

        return water;
    }
};