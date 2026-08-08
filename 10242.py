class Solution:

  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
      return False
    c = [0] * 26
    for i in range(len(s)):
      c[ord(s[i]) - 97] += 1
      c[ord(t[i]) - 97] -= 1
    return not any(c)