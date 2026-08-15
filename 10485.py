class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        m = c = 0
        for n in nums:
            c = c + 1 if n else 0
            if c > m:
                m = c
        return m