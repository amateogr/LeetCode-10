var medianSlidingWindow = function(nums, k) {
    const binarySearch = (arr, target) => {
        let left = 0, right = arr.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (arr[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    };

    const window = nums.slice(0, k).sort((a, b) => a - b);
    const result = [];
    const mid1 = (k - 1) >> 1;
    const mid2 = k >> 1;
    const isEven = k % 2 === 0;

    for (let i = k; ; i++) {
        result.push(isEven ? (window[mid1] + window[mid2]) / 2 : window[mid2]);
        if (i === nums.length) break;
        window.splice(binarySearch(window, nums[i - k]), 1);
        const val = nums[i];
        window.splice(binarySearch(window, val), 0, val);
    }

    return result;
};