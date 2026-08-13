const nearestPalindromic = (n) => {
    const len = n.length;
    const num = BigInt(n);
    const candidates = new Set();
    
    candidates.add(10n ** BigInt(len - 1) - 1n);
    candidates.add(10n ** BigInt(len) + 1n);
    
    const prefixLen = Math.ceil(len / 2);
    const prefix = BigInt(n.slice(0, prefixLen));
    
    for (let i = -1n; i <= 1n; i++) {
        const p = prefix + i;
        const pStr = p.toString();
        const candidateStr = len % 2 === 0 
            ? pStr + pStr.split("").reverse().join("") 
            : pStr + pStr.slice(0, -1).split("").reverse().join("");
        candidates.add(BigInt(candidateStr));
    }
    
    candidates.delete(num);
    
    let result = -1n;
    let minDiff = -1n;
    
    for (const c of candidates) {
        const diff = c > num ? c - num : num - c;
        if (minDiff === -1n || diff < minDiff || (diff === minDiff && c < result)) {
            minDiff = diff;
            result = c;
        }
    }
    
    return result.toString();
};