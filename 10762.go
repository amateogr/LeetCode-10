package leetcode

import "math/bits"

func countPrimeSetBits(left int, right int) int {
	ans := 0
	const mask = 665772
	for i := left; i <= right; i++ {
		if (mask & (1 << bits.OnesCount(uint(i)))) != 0 {
			ans++
		}
	}
	return ans
}
