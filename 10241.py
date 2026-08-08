from functools import lru_cache

class Solution:
    def diffWaysToCompute(self, expression: str) -> list[int]:
        @lru_cache(None)
        def helper(expr):
            if expr.isdigit():
                return [int(expr)]
            res = []
            for i, c in enumerate(expr):
                if c in "+-*":
                    for l in helper(expr[:i]):
                        for r in helper(expr[i+1:]):
                            res.append(l + r if c == '+' else l - r if c == '-' else l * r)
            return res
        return helper(expression)