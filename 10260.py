class Solution:
    def singleNumber(self, nums: list[int]) -> list[int]:
        xor = 0
        for n in nums:
            xor ^= n
        diff = xor & -xor
        a = 0
        for n in nums:
            if n & diff:
                a ^= n
        return [a, xor ^ a]