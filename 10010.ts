function isMatch(s: string, p: string): boolean {
    const memo = new Map<string, boolean>();
    
    function dp(i: number, j: number): boolean {
        const key = `${i},${j}`;
        if (memo.has(key)) {
            return memo.get(key)!;
        }
        
        if (j === p.length) {
            return i === s.length;
        }
        
        const firstMatch = i < s.length && (p[j] === s[i] || p[j] === '.');
        
        let ans: boolean;
        if (j + 1 < p.length && p[j + 1] === '*') {
            ans = dp(i, j + 2) || (firstMatch && dp(i + 1, j));
        } else {
            ans = firstMatch && dp(i + 1, j + 1);
        }
        
        memo.set(key, ans);
        return ans;
    }
    
    return dp(0, 0);
}