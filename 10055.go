package leetcode

func canJump(nums []int) bool {
	maxReach := 0
	for i, val := range nums {
		if i > maxReach {
			return false
		}
		if i+val > maxReach {
			maxReach = i + val
		}
	}
	return true
}
