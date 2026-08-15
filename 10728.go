package leetcode

func selfDividingNumbers(left int, right int) []int {
	res := make([]int, 0, right-left+1)
	for i := left; i <= right; i++ {
		n := i
		valid := true
		for n > 0 {
			d := n % 10
			if d == 0 || i%d != 0 {
				valid = false
				break
			}
			n /= 10
		}
		if valid {
			res = append(res, i)
		}
	}
	return res
}
