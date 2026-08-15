import math

class Solution:
    def constructRectangle(self, area: int) -> list[int]:
        w = math.isqrt(area)
        while area % w:
            w -= 1
        return [area // w, w]