class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly = [1] * n
        i2 = i3 = i5 = 0
        for i in range(1, n):
            u2, u3, u5 = ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5
            nxt = min(u2, u3, u5)
            ugly[i] = nxt
            if nxt == u2:
                i2 += 1
            if nxt == u3:
                i3 += 1
            if nxt == u5:
                i5 += 1
        return ugly[-1]