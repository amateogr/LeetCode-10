package leetcode

func smallestRangeI(nums []int, k int) int {
	mn, mx := nums[0], nums[0]
	for _, v := range nums {
		if v < mn {
			mn = v
		} else if v > mx {
			mx = v
		}
	}
	if res := mx - mn - 2*k; res > 0 {
		return res
	}
	return 0
}
