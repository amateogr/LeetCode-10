package leetcode

import "math"

func maximumProduct(nums []int) int {
	min1, min2 := math.MaxInt, math.MaxInt
	max1, max2, max3 := math.MinInt, math.MinInt, math.MinInt
	for _, n := range nums {
		if n < min1 {
			min2 = min1
			min1 = n
		} else if n < min2 {
			min2 = n
		}
		if n > max1 {
			max3 = max2
			max2 = max1
			max1 = n
		} else if n > max2 {
			max3 = max2
			max2 = n
		} else if n > max3 {
			max3 = n
		}
	}
	if p1 := min1 * min2 * max1; p1 > max1*max2*max3 {
		return p1
	}
	return max1 * max2 * max3
}
