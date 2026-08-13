var outerTrees = function(trees) {
    if (trees.length <= 3) return trees;
    trees.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    const cross = (p, q, r) => (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    const lower = [];
    for (let i = 0; i < trees.length; i++) {
        while (lower.length >= 2 && cross(lower[lower.length - 2], lower[lower.length - 1], trees[i]) < 0) {
            lower.pop();
        }
        lower.push(trees[i]);
    }
    const upper = [];
    for (let i = trees.length - 1; i >= 0; i--) {
        while (upper.length >= 2 && cross(upper[upper.length - 2], upper[upper.length - 1], trees[i]) < 0) {
            upper.pop();
        }
        upper.push(trees[i]);
    }
    const map = new Map();
    for (let i = 0; i < lower.length; i++) map.set(lower[i][0] + ',' + lower[i][1], lower[i]);
    for (let i = 0; i < upper.length; i++) map.set(upper[i][0] + ',' + upper[i][1], upper[i]);
    return Array.from(map.values());
};