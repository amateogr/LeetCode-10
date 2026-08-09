function countRangeSum(nums: number[], lower: number, upper: number): number {
    const n = nums.length;
    const prefixSum = new Float64Array(n + 1);
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    const aux = new Float64Array(n + 1);

    function mergeSort(left: number, right: number): number {
        if (left >= right) return 0;
        const mid = (left + right) >> 1;
        let count = mergeSort(left, mid) + mergeSort(mid + 1, right);

        let k = mid + 1, l = mid + 1;
        for (let i = left; i <= mid; i++) {
            while (k <= right && prefixSum[k] - prefixSum[i] < lower) k++;
            while (l <= right && prefixSum[l] - prefixSum[i] <= upper) l++;
            count += l - k;
        }

        let p1 = left, p2 = mid + 1, idx = left;
        while (p1 <= mid && p2 <= right) {
            if (prefixSum[p1] <= prefixSum[p2]) {
                aux[idx++] = prefixSum[p1++];
            } else {
                aux[idx++] = prefixSum[p2++];
            }
        }
        while (p1 <= mid) aux[idx++] = prefixSum[p1++];
        while (p2 <= right) aux[idx++] = prefixSum[p2++];

        for (let i = left; i <= right; i++) {
            prefixSum[i] = aux[i];
        }

        return count;
    }

    return mergeSort(0, n);
}