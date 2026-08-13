const maxSubarrayLength = (nums, k) => {
    const freq = new Map();
    let left = 0, maxLength = 0;
    
    for (let right = 0; right < nums.length; right++) {
        const x = nums[right];
        freq.set(x, (freq.get(x) || 0) + 1);
        
        while (freq.get(x) > k) {
            const lVal = nums[left];
            freq.set(lVal, freq.get(lVal) - 1);
            left++;
        }
        
        maxLength = Math.max(maxLength, right - left + 1);
    }
    
    return maxLength;
};