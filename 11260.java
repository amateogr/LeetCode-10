import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int total = m * n;
        k %= total;

        List<List<Integer>> result = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            result.add(new ArrayList<>(n));
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newIdx = i * n + j;
                int origIdx = (newIdx - k + total) % total;
                result.get(i).add(grid[origIdx / n][origIdx % n]);
            }
        }

        return result;
    }
}