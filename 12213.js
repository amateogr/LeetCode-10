var longestRepeating = function(s, queryCharacters, queryIndices) {
    const n = s.length;
    const size = 4 * n;
    const max = new Int32Array(size);
    const prefix = new Int32Array(size);
    const suffix = new Int32Array(size);
    const len = new Int32Array(size);
    const lc = new Uint8Array(size);
    const rc = new Uint8Array(size);

    const pushUp = (u) => {
        const left = u << 1;
        const right = left | 1;
        len[u] = len[left] + len[right];
        lc[u] = lc[left];
        rc[u] = rc[right];
        max[u] = Math.max(max[left], max[right]);
        prefix[u] = prefix[left];
        suffix[u] = suffix[right];
        if (rc[left] === lc[right]) {
            if (prefix[left] === len[left]) {
                prefix[u] += prefix[right];
            }
            if (suffix[right] === len[right]) {
                suffix[u] += suffix[left];
            }
            max[u] = Math.max(max[u], suffix[left] + prefix[right]);
        }
    };

    const build = (u, l, r) => {
        if (l === r) {
            len[u] = 1;
            max[u] = 1;
            prefix[u] = 1;
            suffix[u] = 1;
            const code = s.charCodeAt(l - 1);
            lc[u] = code;
            rc[u] = code;
            return;
        }
        const mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushUp(u);
    };

    const update = (u, l, r, x, val) => {
        if (l === r) {
            lc[u] = val;
            rc[u] = val;
            return;
        }
        const mid = (l + r) >> 1;
        if (x <= mid) {
            update(u << 1, l, mid, x, val);
        } else {
            update(u << 1 | 1, mid + 1, r, x, val);
        }
        pushUp(u);
    };

    build(1, 1, n);

    const k = queryIndices.length;
    const ans = new Array(k);
    for (let i = 0; i < k; i++) {
        update(1, 1, n, queryIndices[i] + 1, queryCharacters.charCodeAt(i));
        ans[i] = max[1];
    }
    return ans;
};