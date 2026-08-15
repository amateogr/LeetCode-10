package leetcode

func projectionArea(grid [][]int) int {
	n := len(grid)
	xy, zx := 0, 0
	colMax := make([]int, n)
	for i := 0; i < n; i++ {
		rowMax := 0
		for j := 0; j < n; j++ {
			v := grid[i][j]
			if v > 0 {
				xy++
			}
			if v > rowMax {
				rowMax = v
			}
			if v > colMax[j] {
				colMax[j] = v
			}
		}
		zx += rowMax
	}
	yz := 0
	for _, m := range colMax {
		yz += m
	}
	return xy + zx + yz
}
