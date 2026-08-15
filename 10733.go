package leetcode

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	orig := image[sr][sc]
	if orig == color {
		return image
	}

	var fill func(int, int)
	fill = func(r, c int) {
		if r < 0 || r >= len(image) || c < 0 || c >= len(image[0]) || image[r][c] != orig {
			return
		}
		image[r][c] = color
		fill(r-1, c)
		fill(r+1, c)
		fill(r, c-1)
		fill(r, c+1)
	}

	fill(sr, sc)
	return image
}
