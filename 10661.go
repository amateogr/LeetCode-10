package leetcode

func imageSmoother(img [][]int) [][]int {
	m := len(img)
	n := len(img[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			sum := 0
			count := 0
			for r := i - 1; r <= i+1; r++ {
				for c := j - 1; c <= j+1; c++ {
					if r >= 0 && r < m && c >= 0 && c < n {
						sum += img[r][c] & 255
						count++
					}
				}
			}
			img[i][j] |= (sum / count) << 8
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			img[i][j] >>= 8
		}
	}
	return img
}
