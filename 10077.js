const combine = (n, k) => {
    const result = [];
    const current = [];
    const dfs = (start) => {
        if (current.length === k) {
            result.push([...current]);
            return;
        }
        const left = k - current.length;
        for (let i = start; i <= n - left + 1; i++) {
            current.push(i);
            dfs(i + 1);
            current.pop();
        }
    };
    dfs(1);
    return result;
};