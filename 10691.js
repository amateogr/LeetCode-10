var minStickers = function(stickers, target) {
    const targetFreq = new Array(26).fill(0);
    for (let i = 0; i < target.length; i++) {
        targetFreq[target.charCodeAt(i) - 97]++;
    }

    const counts = [];
    for (const s of stickers) {
        const count = new Array(26).fill(0);
        let valid = false;
        for (let i = 0; i < s.length; i++) {
            const idx = s.charCodeAt(i) - 97;
            if (targetFreq[idx] > 0) {
                count[idx]++;
                valid = true;
            }
        }
        if (valid) counts.push(count);
    }

    const memo = new Map();
    memo.set("", 0);

    const dfs = (t) => {
        if (memo.has(t)) return memo.get(t);

        const tCount = new Array(26).fill(0);
        for (let i = 0; i < t.length; i++) {
            tCount[t.charCodeAt(i) - 97]++;
        }

        let min = Infinity;
        const firstIdx = t.charCodeAt(0) - 97;

        for (const sticker of counts) {
            if (sticker[firstIdx] === 0) continue;

            let nextT = "";
            for (let j = 0; j < 26; j++) {
                if (tCount[j] > 0) {
                    const rem = tCount[j] - sticker[j];
                    if (rem > 0) {
                        nextT += String.fromCharCode(j + 97).repeat(rem);
                    }
                }
            }

            const res = dfs(nextT);
            if (res !== -1) min = Math.min(min, 1 + res);
        }

        const result = min === Infinity ? -1 : min;
        memo.set(t, result);
        return result;
    };

    return dfs(target.split('').sort().join(''));
};