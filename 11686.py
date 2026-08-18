class Solution:
    def stoneGameVI(self, aliceValues: list[int], bobValues: list[int]) -> int:
        v = sorted(((a + b, i) for i, (a, b) in enumerate(zip(aliceValues, bobValues))), reverse=True)
        a = sum(aliceValues[v[i][1]] for i in range(0, len(v), 2))
        b = sum(bobValues[v[i][1]] for i in range(1, len(v), 2))
        return (a > b) - (a < b)