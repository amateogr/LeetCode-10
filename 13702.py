class Solution:
    def longestSubsequence(self, nums: list[int]) -> int:
        t = 0
        for x in nums:
            t ^= x
        if t:
            return len(nums)
        return len(nums) - 1 if any(nums) else 0