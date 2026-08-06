class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        s, m, heights = [], 0, heights + [0]
        for i, h in enumerate(heights):
            while s and heights[s[-1]] > h:
                hi = heights[s.pop()]
                w = i if not s else i - s[-1] - 1
                m = max(m, hi * w)
            s.append(i)
        heights.pop()
        return m