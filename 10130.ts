function solve(board: string[][]): void {
    const m = board.length;
    const n = board[0].length;
    const q: number[] = [];

    for (let i = 0; i < m; i++) {
        if (board[i][0] === 'O') { board[i][0] = 'E'; q.push(i * n); }
        if (board[i][n - 1] === 'O') { board[i][n - 1] = 'E'; q.push(i * n + n - 1); }
    }
    for (let j = 1; j < n - 1; j++) {
        if (board[0][j] === 'O') { board[0][j] = 'E'; q.push(j); }
        if (board[m - 1][j] === 'O') { board[m - 1][j] = 'E'; q.push((m - 1) * n + j); }
    }

    let head = 0;
    while (head < q.length) {
        const curr = q[head++];
        const r = Math.floor(curr / n);
        const c = curr % n;

        if (r > 0 && board[r - 1][c] === 'O') { board[r - 1][c] = 'E'; q.push((r - 1) * n + c); }
        if (r < m - 1 && board[r + 1][c] === 'O') { board[r + 1][c] = 'E'; q.push((r + 1) * n + c); }
        if (c > 0 && board[r][c - 1] === 'O') { board[r][c - 1] = 'E'; q.push(r * n + c - 1); }
        if (c < n - 1 && board[r][c + 1] === 'O') { board[r][c + 1] = 'E'; q.push(r * n + c + 1); }
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'O') board[i][j] = 'X';
            else if (board[i][j] === 'E') board[i][j] = 'O';
        }
    }
};