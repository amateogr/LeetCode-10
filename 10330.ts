function minPatches(nums: number[], n: number): number {
    let patches = 0, i = 0, miss = 1;
    while (miss <= n) {
        if (i < nums.length && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            miss += miss;
            patches++;
        }
    }
    return patches;
}