const maximumLengthSubstring = (s) => {
    let maxLen = 0;
    let left = 0;
    const freq = new Uint8Array(128);

    for (let right = 0; right < s.length; right++) {
        const charCode = s.charCodeAt(right);
        freq[charCode]++;

        while (freq[charCode] > 2) {
            freq[s.charCodeAt(left)]--;
            left++;
        }

        const currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
};