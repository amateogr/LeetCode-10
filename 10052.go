package leetcode

func totalNQueens(n int) int {
	var count int
	var dfs func(row, cols, diag1, diag2 int)
	dfs = func(row, cols, diag1, diag2 int) {
		if row == n {
			count++
			return
		}
		availableBits := ((1 << n) - 1) & ^(cols | diag1 | diag2)
		for availableBits != 0 {
			p := availableBits & -availableBits
			availableBits -= p
			dfs(row+1, cols|p, (diag1|p)<<1, (diag2|p)>>1)
		}
	}
	dfs(0, 0, 0, 0)
	return count
}
