const kInversePairs = (n, k) => {
    const MOD = 1000000007;
    let dp = new Int32Array(k + 1);
    dp[0] = 1;

    for (let i = 1; i <= n; i++) {
        const temp = new Int32Array(k + 1);
        let sum = 0;
        for (let j = 0; j <= k; j++) {
            sum = (sum + dp[j]) % MOD;
            if (j >= i) {
                sum = (sum - dp[j - i] + MOD) % MOD;
            }
            temp[j] = sum;
        }
        dp = temp;
    }

    return dp[k];
};