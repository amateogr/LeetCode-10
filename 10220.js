var containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    if (valueDiff < 0 || indexDiff <= 0) return false;
    const bucket = new Map();
    const width = valueDiff + 1;
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const bucketId = Math.floor(num / width);
        if (bucket.has(bucketId)) return true;
        if (bucket.has(bucketId - 1) && Math.abs(num - bucket.get(bucketId - 1)) <= valueDiff) return true;
        if (bucket.has(bucketId + 1) && Math.abs(num - bucket.get(bucketId + 1)) <= valueDiff) return true;
        bucket.set(bucketId, num);
        if (i >= indexDiff) {
            const oldNum = nums[i - indexDiff];
            const oldBucketId = Math.floor(oldNum / width);
            bucket.delete(oldBucketId);
        }
    }
    return false;
};