package leetcode

func isToeplitzMatrix(matrix [][]int) bool {
	for i := 0; i < len(matrix)-1; i++ {
		r1, r2 := matrix[i], matrix[i+1]
		for j := 0; j < len(r1)-1; j++ {
			if r1[j] != r2[j+1] {
				return false
			}
		}
	}
	return true
}
