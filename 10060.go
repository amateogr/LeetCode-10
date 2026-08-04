package leetcode

import (
	"strconv"
	"strings"
)

func getPermutation(n int, k int) string {
	numbers := []int{}
	factorial := 1
	for i := 1; i <= n; i++ {
		numbers = append(numbers, i)
		if i < n {
			factorial *= i
		}
	}
	k--
	var result strings.Builder
	for i := n; i > 0; i-- {
		idx := k / factorial
		result.WriteString(strconv.Itoa(numbers[idx]))
		numbers = append(numbers[:idx], numbers[idx+1:]...)
		if i > 1 {
			k %= factorial
			factorial /= (i - 1)
		}
	}
	return result.String()
}
