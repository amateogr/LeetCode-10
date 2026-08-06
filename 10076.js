function minWindow(s, t) {
    if (s.length < t.length) return "";
    
    const countT = new Int32Array(128);
    const windowCount = new Int32Array(128);
    
    for (let i = 0; i < t.length; i++) {
        countT[t.charCodeAt(i)]++;
    }
    
    let required = 0;
    for (let i = 0; i < 128; i++) {
        if (countT[i] > 0) required++;
    }
    
    let formed = 0;
    let l = 0;
    let minLen = Infinity;
    let minLeft = 0;
    
    for (let r = 0; r < s.length; r++) {
        const c = s.charCodeAt(r);
        windowCount[c]++;
        
        if (countT[c] > 0 && windowCount[c] === countT[c]) {
            formed++;
        }
        
        while (l <= r && formed === required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                minLeft = l;
            }
            
            const leftChar = s.charCodeAt(l);
            windowCount[leftChar]--;
            if (countT[leftChar] > 0 && windowCount[leftChar] < countT[leftChar]) {
                formed--;
            }
            l++;
        }
    }
    
    return minLen === Infinity ? "" : s.substring(minLeft, minLeft + minLen);
}