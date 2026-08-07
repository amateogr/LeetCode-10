import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        var res = new ArrayList<List<Integer>>();
        dfs(1, k, n, new ArrayList<>(), res);
        return res;
    }

    private void dfs(int start, int k, int n, List<Integer> path, List<List<Integer>> res) {
        if (path.size() == k && n == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (path.size() >= k || n <= 0) {
            return;
        }
        for (int i = start; i <= 9 && i <= n; i++) {
            path.add(i);
            dfs(i + 1, k, n - i, path, res);
            path.remove(path.size() - 1);
        }
    }
}