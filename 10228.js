const summaryRanges = function(nums) {
    const res = [];
    for (let i = 0; i < nums.length; i++) {
        let start = nums[i];
        while (i + 1 < nums.length && nums[i + 1] === nums[i] + 1) i++;
        res.push(start === nums[i] ? `${start}` : `${start}->${nums[i]}`);
    }
    return res;
};