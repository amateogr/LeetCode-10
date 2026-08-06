class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        n2, n1 = 1, 1
        for i in range(1, len(s)):
            c = 0
            if s[i] != '0':
                c += n1
            if 10 <= int(s[i-1:i+1]) <= 26:
                c += n2
            n2, n1 = n1, c
        return n1