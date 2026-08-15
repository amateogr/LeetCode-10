class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        first = second = third = float('-inf')
        for n in nums:
            if n > first:
                third, second, first = second, first, n
            elif first > n > second:
                third, second = second, n
            elif second > n > third:
                third = n
        return third if third != float('-inf') else first