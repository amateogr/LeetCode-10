function wordBreak(s: string, wordDict: string[]): boolean {
    const wordSet = new Set(wordDict);
    let maxLength = 0;
    
    for (const word of wordDict) {
        if (word.length > maxLength) {
            maxLength = word.length;
        }
    }

    const dp: boolean[] = new Array(s.length + 1).fill(false);
    dp[0] = true;

    for (let i = 1; i <= s.length; i++) {
        for (let j = Math.max(0, i - maxLength); j < i; j++) {
            if (dp[j] && wordSet.has(s.substring(j, i))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.length];
}