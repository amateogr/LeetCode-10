const findAllConcatenatedWordsInADict = (words) => {
    words.sort((a, b) => a.length - b.length);
    const wordSet = new Set();
    const result = [];
    
    for (const word of words) {
        if (word.length > 0) {
            const dp = new Array(word.length + 1).fill(false);
            dp[0] = true;
            for (let i = 1; i <= word.length; i++) {
                for (let j = 0; j < i; j++) {
                    if (dp[j] && wordSet.has(word.slice(j, i))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[word.length]) {
                result.push(word);
            }
        }
        wordSet.add(word);
    }
    
    return result;
};