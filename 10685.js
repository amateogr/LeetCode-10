const findRedundantDirectedConnection = (edges) => {
    const n = edges.length;
    const parent = new Int32Array(n + 1);
    let cand1 = null;
    let cand2 = null;

    for (let i = 0; i < n; i++) {
        const [u, v] = edges[i];
        if (parent[v] !== 0) {
            cand1 = [parent[v], v];
            cand2 = [u, v];
            break;
        }
        parent[v] = u;
    }

    const dsu = new Int32Array(n + 1);
    for (let i = 1; i <= n; i++) {
        dsu[i] = i;
    }

    const find = (i) => {
        let root = i;
        while (root !== dsu[root]) {
            dsu[root] = dsu[dsu[root]];
            root = dsu[root];
        }
        return root;
    };

    for (let i = 0; i < n; i++) {
        const [u, v] = edges[i];
        if (cand2 && u === cand2[0] && v === cand2[1]) continue;

        const rootU = find(u);
        const rootV = find(v);

        if (rootU === rootV) {
            if (cand1) return cand1;
            return [u, v];
        }
        dsu[rootV] = rootU;
    }

    return cand2;
};