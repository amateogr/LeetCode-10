class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:
        p = 0
        h = len(grid)
        w = len(grid[0])
        for r in range(h):
            for c in range(w):
                if grid[r][c]:
                    p += 4
                    if r and grid[r - 1][c]:
                        p -= 2
                    if c and grid[r][c - 1]:
                        p -= 2
        return p