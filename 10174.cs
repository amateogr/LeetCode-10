using System;

public class Solution {
    public int CalculateMinimumHP(int[][] dungeon) {
        int m = dungeon.Length;
        int n = dungeon[0].Length;
        int[] dp = new int[n + 1];
        
        Array.Fill(dp, int.MaxValue);
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[j] = Math.Max(1, Math.Min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }

        return dp[0];
    }
}