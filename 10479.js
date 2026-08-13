var largestPalindrome = function(n) {
    if (n === 1) return 9;
    const MOD = 1337n;
    const upper = 10n ** BigInt(n) - 1n;
    const lower = 10n ** BigInt(n - 1) - 1n;
    for (let i = upper; i > lower; i--) {
        const s = i.toString();
        const cand = BigInt(s + s.split('').reverse().join(''));
        let j = upper;
        while (j * j >= cand) {
            if (cand % j === 0n) {
                return Number(cand % MOD);
            }
            j--;
        }
    }
};