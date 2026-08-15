package leetcode

func flipAndInvertImage(image [][]int) [][]int {
	for _, row := range image {
		n := len(row)
		for i := 0; i < (n+1)/2; i++ {
			j := n - 1 - i
			row[i], row[j] = row[j]^1, row[i]^1
		}
	}
	return image
}
