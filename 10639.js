var numDecodings = function(s) {
    const MOD = 1e9 + 7;
    const n = s.length;
    
    let prev = 1;
    let curr = s.charCodeAt(0) === 48 ? 0 : (s.charCodeAt(0) === 42 ? 9 : 1);

    for (let i = 1; i < n; i++) {
        let next = 0;
        const c1 = s.charCodeAt(i);
        const c2 = s.charCodeAt(i - 1);

        if (c1 === 42) {
            next += 9 * curr;
        } else if (c1 !== 48) {
            next += curr;
        }

        if (c2 === 42) {
            if (c1 === 42) {
                next += 15 * prev;
            } else if (c1 <= 54) {
                next += 2 * prev;
            } else {
                next += prev;
            }
        } else if (c2 === 49) {
            if (c1 === 42) {
                next += 9 * prev;
            } else {
                next += prev;
            }
        } else if (c2 === 50) {
            if (c1 === 42) {
                next += 6 * prev;
            } else if (c1 <= 54) {
                next += prev;
            }
        }

        prev = curr;
        curr = next % MOD;
    }

    return curr;
};