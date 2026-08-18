class Solution:
    def rand10(self) -> int:
        while True:
            t = (rand7() - 1) * 7 + rand7()
            if t <= 40:
                return (t - 1) % 10 + 1