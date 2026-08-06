const minDistance = (word1, word2) => {
    if (word1.length < word2.length) [word1, word2] = [word2, word1];
    const m = word1.length, n = word2.length;
    const dp = new Int32Array(n + 1).map((_, i) => i);
    
    for (let i = 1; i <= m; i++) {
        let prev = dp[0];
        dp[0] = i;
        for (let j = 1; j <= n; j++) {
            const temp = dp[j];
            dp[j] = word1[i - 1] === word2[j - 1] 
                ? prev 
                : 1 + Math.min(prev, dp[j], dp[j - 1]);
            prev = temp;
        }
    }
    return dp[n];
};