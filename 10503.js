function nextGreaterElements(nums) {
    const n = nums.length;
    const res = new Array(n).fill(-1);
    const stack = [];
    
    for (let i = (n * 2) - 1; i >= 0; i--) {
        const idx = i % n;
        while (stack.length > 0 && nums[stack[stack.length - 1]] <= nums[idx]) {
            stack.pop();
        }
        if (i < n && stack.length > 0) {
            res[idx] = nums[stack[stack.length - 1]];
        }
        stack.push(idx);
    }
    
    return res;
}