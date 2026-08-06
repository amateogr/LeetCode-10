function partition(s: string): string[][] {
    const n = s.length;
    const dp: boolean[][] = Array.from({ length: n }, () => Array(n).fill(true));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            dp[i][j] = s[i] === s[j] && dp[i + 1][j - 1];
        }
    }
    const res: string[][] = [];
    const path: string[] = [];
    const dfs = (startIndex: number) => {
        if (startIndex === n) {
            res.push([...path]);
            return;
        }
        for (let i = startIndex; i < n; i++) {
            if (dp[startIndex][i]) {
                path.push(s.slice(startIndex, i + 1));
                dfs(i + 1);
                path.pop();
            }
        }
    };
    dfs(0);
    return res;
}