var smallestGoodBase = function(nStr) {
    const n = BigInt(nStr);
    for (let m = 60; m >= 1; m--) {
        let l = 2n;
        let r = n;
        while (l <= r) {
            const k = (l + r) / 2n;
            let sum = 0n;
            let p = 1n;
            let overflow = false;
            for (let i = 0; i <= m; i++) {
                sum += p;
                if (sum > n) {
                    overflow = true;
                    break;
                }
                if (i < m) p *= k;
            }
            if (overflow || sum > n) {
                r = k - 1n;
            } else if (sum < n) {
                l = k + 1n;
            } else {
                return k.toString();
            }
        }
    }
};