class Solution:
    def fizzBuzz(self, n: int) -> list[str]:
        ans = [None] * n
        for i in range(1, n + 1):
            s = ""
            if i % 3 == 0:
                s += "Fizz"
            if i % 5 == 0:
                s += "Buzz"
            ans[i - 1] = s or str(i)
        return ans