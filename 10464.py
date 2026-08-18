from functools import lru_cache


class Solution:

  def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
    if desiredTotal <= 0:
      return True
    total_sum = maxChoosableInteger * (maxChoosableInteger + 1) // 2
    if total_sum < desiredTotal:
      return False
    if total_sum == desiredTotal:
      return maxChoosableInteger % 2 == 1

    @lru_cache(None)
    def dp(mask, remainder):
      for i in range(1, maxChoosableInteger + 1):
        if not (mask & (1 << i)):
          if remainder <= i or not dp(mask | (1 << i), remainder - i):
            return True
      return False

    return dp(0, desiredTotal)