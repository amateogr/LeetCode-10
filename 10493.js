var reversePairs = function(nums) {
    const temp = new Int32Array(nums.length);
    
    const mergeSort = (left, right) => {
        if (left >= right) return 0;
        
        const mid = (left + right) >> 1;
        let count = mergeSort(left, mid) + mergeSort(mid + 1, right);
        
        let j = mid + 1;
        for (let i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2 * nums[j]) j++;
            count += j - (mid + 1);
        }
        
        let i = left;
        j = mid + 1;
        let k = left;
        
        while (i <= mid && j <= right) {
            temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        }
        
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        
        for (let p = left; p <= right; p++) nums[p] = temp[p];
        
        return count;
    };
    
    return mergeSort(0, nums.length - 1);
};