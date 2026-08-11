#include <stdlib.h>
#include <limits.h>
#include <string.h>

int getMoneyAmount(int n) {
    int dp[205][205];
    memset(dp, 0, sizeof(dp));

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            int min_cost = INT_MAX;
            for (int k = i; k <= j; ++k) {
                int left = (k > i) ? dp[i][k - 1] : 0;
                int right = (k < j) ? dp[k + 1][j] : 0;
                int cost = k + (left > right ? left : right);
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            dp[i][j] = min_cost;
        }
    }
    return dp[1][n];
}