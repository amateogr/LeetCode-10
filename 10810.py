class Solution:
    def xorGame(self, nums: list[int]) -> bool:
        if len(nums) & 1 == 0:
            return True
        
        x = 0
        for n in nums:
            x ^= n
            
        return x == 0