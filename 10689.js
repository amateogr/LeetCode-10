function maxSumOfThreeSubarrays(nums, k) {
    const n = nums.length;
    const sums = new Int32Array(n - k + 1);
    let currentSum = 0;

    for (let i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    sums[0] = currentSum;

    for (let i = k; i < n; i++) {
        currentSum += nums[i] - nums[i - k];
        sums[i - k + 1] = currentSum;
    }

    const left = new Int32Array(sums.length);
    let bestLeft = 0;
    for (let i = 0; i < sums.length; i++) {
        if (sums[i] > sums[bestLeft]) {
            bestLeft = i;
        }
        left[i] = bestLeft;
    }

    const right = new Int32Array(sums.length);
    let bestRight = sums.length - 1;
    for (let i = sums.length - 1; i >= 0; i--) {
        if (sums[i] >= sums[bestRight]) {
            bestRight = i;
        }
        right[i] = bestRight;
    }

    const result = [0, 0, 0];
    let maxSum = 0;

    for (let j = k; j < sums.length - k; j++) {
        const l = left[j - k];
        const r = right[j + k];
        const total = sums[l] + sums[j] + sums[r];

        if (total > maxSum) {
            maxSum = total;
            result[0] = l;
            result[1] = j;
            result[2] = r;
        }
    }

    return result;
}