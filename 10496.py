class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        stack, mapping = [], {}
        for x in reversed(nums2):
            while stack and stack[-1] <= x:
                stack.pop()
            mapping[x] = stack[-1] if stack else -1
            stack.append(x)
        return [mapping[x] for x in nums1]