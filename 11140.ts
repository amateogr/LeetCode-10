function stoneGameII(piles: number[]): number {
    const n = piles.length;
    const suffixSum = new Int32Array(n + 1);
    for (let i = n - 1; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + piles[i];
    }
    
    const memo: number[][] = Array.from({ length: n }, () => new Array(n + 1).fill(0));

    function dp(i: number, m: number): number {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffixSum[i];
        if (memo[i][m] !== 0) return memo[i][m];

        let res = 0;
        for (let x = 1; x <= 2 * m; x++) {
            res = Math.max(res, suffixSum[i] - dp(i + x, Math.max(m, x)));
        }
        
        memo[i][m] = res;
        return res;
    }

    return dp(0, 1);
}