class Solution:

  def predictTheWinner(self, nums: list[int]) -> bool:
    n = len(nums)
    dp = list(nums)
    for l in range(2, n + 1):
      for i in range(n - l + 1):
        dp[i] = max(nums[i] - dp[i + 1], nums[i + l - 1] - dp[i])
    return dp[0] >= 0