function maxNumber(nums1: number[], nums2: number[], k: number): number[] {
    const m = nums1.length;
    const n = nums2.length;
    let best: number[] = [];
    
    const getMaxSubsequence = (nums: number[], k: number): number[] => {
        const res: number[] = [];
        let drop = nums.length - k;
        for (const num of nums) {
            while (res.length > 0 && res[res.length - 1] < num && drop > 0) {
                res.pop();
                drop--;
            }
            res.push(num);
        }
        res.length = k;
        return res;
    };
    
    const greater = (arr1: number[], i: number, arr2: number[], j: number): boolean => {
        while (i < arr1.length && j < arr2.length && arr1[i] === arr2[j]) {
            i++;
            j++;
        }
        return j === arr2.length || (i < arr1.length && arr1[i] > arr2[j]);
    };
    
    const merge = (arr1: number[], arr2: number[]): number[] => {
        const res: number[] = [];
        let i = 0, j = 0;
        while (i < arr1.length || j < arr2.length) {
            if (greater(arr1, i, arr2, j)) {
                res.push(arr1[i++]);
            } else {
                res.push(arr2[j++]);
            }
        }
        return res;
    };
    
    const compareArrays = (arr1: number[], arr2: number[]): number => {
        for (let i = 0; i < arr1.length; i++) {
            if (arr1[i] !== arr2[i]) {
                return arr1[i] - arr2[i];
            }
        }
        return 0;
    };
    
    const start = Math.max(0, k - n);
    const end = Math.min(k, m);
    
    for (let i = start; i <= end; i++) {
        const sub1 = getMaxSubsequence(nums1, i);
        const sub2 = getMaxSubsequence(nums2, k - i);
        const candidate = merge(sub1, sub2);
        if (best.length === 0 || compareArrays(candidate, best) > 0) {
            best = candidate;
        }
    }
    
    return best;
}