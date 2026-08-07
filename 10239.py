from collections import deque
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = deque()
        res = []
        for i, n in enumerate(nums):
            while d and d[0] < i - k + 1:
                d.popleft()
            while d and nums[d[-1]] < n:
                d.pop()
            d.append(i)
            if i >= k - 1:
                res.append(nums[d[0]])
        return res     