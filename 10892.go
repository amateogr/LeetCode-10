package leetcode

func surfaceArea(grid [][]int) int {
	n := len(grid)
	var ans int
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if v := grid[i][j]; v > 0 {
				ans += 4*v + 2
				if i > 0 {
					ans -= 2 * min(v, grid[i-1][j])
				}
				if j > 0 {
					ans -= 2 * min(v, grid[i][j-1])
				}
			}
		}
	}
	return ans
}
