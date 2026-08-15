from collections import Counter
class Solution:

  def longestPalindrome(self, s: str) -> int:
    res = sum(v & ~1 for v in Counter(s).values())
    return res + (res < len(s))