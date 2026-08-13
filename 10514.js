const findRotateSteps = (ring, key) => {
    const m = ring.length;
    const n = key.length;
    const pos = Array.from({ length: 26 }, () => []);
    for (let i = 0; i < m; i++) {
        pos[ring.charCodeAt(i) - 97].push(i);
    }
    const memo = Array.from({ length: n }, () => new Int32Array(m).fill(-1));
    const dfs = (keyIdx, ringIdx) => {
        if (keyIdx === n) return 0;
        if (memo[keyIdx][ringIdx] !== -1) return memo[keyIdx][ringIdx];
        let res = Infinity;
        const charCode = key.charCodeAt(keyIdx) - 97;
        for (const nextIdx of pos[charCode]) {
            const diff = Math.abs(nextIdx - ringIdx);
            const steps = Math.min(diff, m - diff) + 1 + dfs(keyIdx + 1, nextIdx);
            if (steps < res) res = steps;
        }
        return memo[keyIdx][ringIdx] = res;
    };
    return dfs(0, 0);
};