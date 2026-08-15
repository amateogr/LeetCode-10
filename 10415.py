class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = []
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        while i >= 0 or j >= 0 or carry:
            x = ord(num1[i]) - 48 if i >= 0 else 0
            y = ord(num2[j]) - 48 if j >= 0 else 0
            carry, rem = divmod(x + y + carry, 10)
            res.append(chr(rem + 48))
            i, j = i - 1, j - 1
        res.reverse()
        return "".join(res)