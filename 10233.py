class Solution:

  def countDigitOne(self, n: int) -> int:
    count = 0
    m = 1
    while m <= n:
      higher = n // (m * 10)
      current = (n // m) % 10
      lower = n % m
      if current == 0:
        count += higher * m
      elif current == 1:
        count += higher * m + lower + 1
      else:
        count += (higher + 1) * m
      m *= 10
    return count