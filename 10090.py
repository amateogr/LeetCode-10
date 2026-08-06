class Solution:

  def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
    nums.sort()
    res = []

    def dfs(i, path):
      res.append(path)
      for j in range(i, len(nums)):
        if j > i and nums[j] == nums[j - 1]:
          continue
        dfs(j + 1, path + [nums[j]])

    dfs(0, [])
    return res