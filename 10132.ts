function minCut(s: string): number {
    const n = s.length;
    const cuts: number[] = new Array(n);
    const p: boolean[][] = Array.from({ length: n }, () => Array(n).fill(false));

    for (let i = 0; i < n; i++) {
        let minC = i;
        for (let j = 0; j <= i; j++) {
            if (s.charCodeAt(j) === s.charCodeAt(i) && (i - j <= 2 || p[j + 1][i - 1])) {
                p[j][i] = true;
                minC = j === 0 ? 0 : Math.min(minC, cuts[j - 1] + 1);
            }
        }
        cuts[i] = minC;
    }

    return cuts[n - 1];
}