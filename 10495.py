class Solution:
    def findPoisonedDuration(self, timeSeries: list[int], duration: int) -> int:
        return sum(min(duration, b - a) for a, b in zip(timeSeries, timeSeries[1:])) + duration