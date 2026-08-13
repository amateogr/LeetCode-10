function strangePrinter(s) {
    if (!s.length) return 0;

    const str = new Uint8Array(s.length);
    let n = 0;
    
    str[n++] = s.charCodeAt(0);
    for (let i = 1; i < s.length; i++) {
        const code = s.charCodeAt(i);
        if (code !== str[n - 1]) {
            str[n++] = code;
        }
    }

    if (n === 1) return 1;

    const dp = new Uint8Array(n * n);

    for (let i = n - 1; i >= 0; i--) {
        dp[i * n + i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (str[i] === str[j]) {
                dp[i * n + j] = dp[i * n + (j - 1)];
            } else {
                let minTurns = 255;
                for (let k = i; k < j; k++) {
                    const turns = dp[i * n + k] + dp[(k + 1) * n + j];
                    if (turns < minTurns) {
                        minTurns = turns;
                    }
                }
                dp[i * n + j] = minTurns;
            }
        }
    }

    return dp[n - 1];
}