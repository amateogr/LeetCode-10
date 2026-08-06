const exist = (board, word) => {
    const rows = board.length;
    const cols = board[0].length;
    if (rows * cols < word.length) return false;

    let firstCount = 0;
    let lastCount = 0;
    const first = word[0];
    const last = word[word.length - 1];

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (board[r][c] === first) firstCount++;
            if (board[r][c] === last) lastCount++;
        }
    }

    const target = firstCount > lastCount ? word.split("").reverse().join("") : word;

    const dfs = (r, c, i) => {
        if (i === target.length) return true;
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] !== target[i]) return false;

        board[r][c] = "#";
        const found = dfs(r + 1, c, i + 1) || dfs(r - 1, c, i + 1) || dfs(r, c + 1, i + 1) || dfs(r, c - 1, i + 1);
        board[r][c] = target[i];
        return found;
    };

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (board[r][c] === target[0] && dfs(r, c, 0)) return true;
        }
    }

    return false;
};