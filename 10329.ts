function longestIncreasingPath(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    const memo: number[][] = Array.from({ length: m }, () => new Int32Array(n) as unknown as number[]);
    let max = 0;

    const dfs = (r: number, c: number): number => {
        if (memo[r][c] !== 0) return memo[r][c];
        let len = 1;
        const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
        for (const [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                len = Math.max(len, 1 + dfs(nr, nc));
            }
        }
        return memo[r][c] = len;
    };

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            max = Math.max(max, dfs(i, j));
        }
    }

    return max;
}