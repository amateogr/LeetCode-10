function singleNumber(nums: number[]): number {
    let ones = 0;
    let twos = 0;
    for (const num of nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}