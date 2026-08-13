function getMaxRepetitions(s1, n1, s2, n2) {
    const len = s2.length;
    const dp = Array.from({ length: len }, () => [0, 0]);

    for (let i = 0; i < len; i++) {
        let j = i;
        let cnt = 0;
        for (let k = 0; k < s1.length; k++) {
            if (s1[k] === s2[j]) {
                j++;
                if (j === len) {
                    j = 0;
                    cnt++;
                }
            }
        }
        dp[i] = [cnt, j];
    }

    let ans = 0;
    let curr = 0;
    for (let i = 0; i < n1; i++) {
        ans += dp[curr][0];
        curr = dp[curr][1];
    }

    return Math.floor(ans / n2);
}