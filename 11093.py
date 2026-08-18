class Solution:
    def sampleStats(self, count: list[int]) -> list[float]:
        total = sum(count)
        min_val = min(i for i, c in enumerate(count) if c > 0)
        max_val = max(i for i, c in enumerate(count) if c > 0)
        mean = sum(i * c for i, c in enumerate(count)) / total
        mode = max(range(256), key=count.__getitem__)
        half1, half2 = (total + 1) // 2, (total + 2) // 2
        curr = 0
        med1 = med2 = None
        for i, c in enumerate(count):
            curr += c
            if med1 is None and curr >= half1:
                med1 = i
            if med2 is None and curr >= half2:
                med2 = i
                break
        return [float(min_val), float(max_val), mean, (med1 + med2) / 2.0, float(mode)]