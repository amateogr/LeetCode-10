package leetcode

func matrixReshape(mat [][]int, r int, c int) [][]int {
	m, n := len(mat), len(mat[0])
	if m*n != r*c {
		return mat
	}
	res := make([][]int, r)
	flat := make([]int, r*c)
	for i := 0; i < r; i++ {
		res[i] = flat[i*c : (i+1)*c]
	}
	for i := 0; i < m*n; i++ {
		res[i/c][i%c] = mat[i/n][i%n]
	}
	return res
}
