class Solution:
    def countSegments(self, s: str) -> int:
        c = 0
        f = True
        for x in s:
            if x == ' ':
                f = True
            elif f:
                c += 1
                f = False
        return c     