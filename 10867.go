package leetcode

func transpose(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		row := make([]int, m)
		for j := 0; j < m; j++ {
			row[j] = matrix[j][i]
		}
		res[i] = row
	}
	return res
}
