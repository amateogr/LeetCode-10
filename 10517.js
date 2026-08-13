const findMinMoves = (machines) => {
    const total = machines.reduce((acc, val) => acc + val, 0);
    const n = machines.length;
    if (total % n !== 0) return -1;
    const target = total / n;
    let maxMoves = 0;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += machines[i] - target;
        maxMoves = Math.max(maxMoves, Math.abs(sum), machines[i] - target);
    }
    return maxMoves;
};