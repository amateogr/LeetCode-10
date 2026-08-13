var judgePoint24 = function(cards) {
    const eps = 1e-6;

    const dfs = (list) => {
        const len = list.length;
        if (len === 1) {
            return Math.abs(list[0] - 24) < eps;
        }

        for (let i = 0; i < len; i++) {
            for (let j = i + 1; j < len; j++) {
                const next = [];
                for (let k = 0; k < len; k++) {
                    if (k !== i && k !== j) {
                        next.push(list[k]);
                    }
                }

                const a = list[i];
                const b = list[j];
                const results = [
                    a + b, 
                    a - b, 
                    b - a, 
                    a * b
                ];

                if (Math.abs(b) > eps) results.push(a / b);
                if (Math.abs(a) > eps) results.push(b / a);

                for (const res of results) {
                    next.push(res);
                    if (dfs(next)) return true;
                    next.pop();
                }
            }
        }
        return false;
    };

    return dfs(cards);
};