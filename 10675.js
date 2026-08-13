const cutOffTree = function(forest) {
    const m = forest.length;
    const n = forest[0].length;
    const trees = [];

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            if (forest[r][c] > 1) {
                trees.push({ h: forest[r][c], r, c });
            }
        }
    }

    trees.sort((a, b) => a.h - b.h);

    const dirs = [0, 1, 0, -1, 0];
    let totalSteps = 0;
    let sr = 0;
    let sc = 0;
    
    const visited = Array.from({ length: m }, () => new Int32Array(n));
    let visitId = 0;

    for (let t = 0; t < trees.length; t++) {
        const target = trees[t];
        visitId++;
        
        const queue = [[sr, sc, 0]];
        let head = 0;
        visited[sr][sc] = visitId;
        
        let found = false;

        while (head < queue.length) {
            const [r, c, steps] = queue[head++];

            if (r === target.r && c === target.c) {
                totalSteps += steps;
                sr = target.r;
                sc = target.c;
                found = true;
                break;
            }

            for (let i = 0; i < 4; i++) {
                const nr = r + dirs[i];
                const nc = c + dirs[i + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] !== 0 && visited[nr][nc] !== visitId) {
                    visited[nr][nc] = visitId;
                    queue.push([nr, nc, steps + 1]);
                }
            }
        }

        if (!found) return -1;
    }

    return totalSteps;
};