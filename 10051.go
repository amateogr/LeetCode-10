package leetcode

func solveNQueens(n int) [][]string {
	var res [][]string
	board := make([][]byte, n)
	for i := range board {
		board[i] = make([]byte, n)
		for j := range board[i] {
			board[i][j] = '.'
		}
	}

	cols := make(map[int]bool)
	diag1 := make(map[int]bool)
	diag2 := make(map[int]bool)

	var backtrack func(r int)
	backtrack = func(r int) {
		if r == n {
			temp := make([]string, n)
			for i := range board {
				temp[i] = string(board[i])
			}
			res = append(res, temp)
			return
		}

		for c := 0; c < n; c++ {
			if cols[c] || diag1[r-c] || diag2[r+c] {
				continue
			}

			cols[c] = true
			diag1[r-c] = true
			diag2[r+c] = true
			board[r][c] = 'Q'

			backtrack(r + 1)

			board[r][c] = '.'
			cols[c] = false
			diag1[r-c] = false
			diag2[r+c] = false
		}
	}

	backtrack(0)
	return res
}
