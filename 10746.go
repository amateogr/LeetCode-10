package leetcode

func minCostClimbingStairs(cost []int) int {
	f1, f2 := 0, 0
	for _, c := range cost {
		f1, f2 = c+min(f1, f2), f1
	}
	return min(f1, f2)
}
