package leetcode

func maxSubArray(nums []int) int {
	maxSum := nums[0]
	currentSum := nums[0]
	for _, num := range nums[1:] {
		if currentSum < 0 {
			currentSum = num
		} else {
			currentSum += num
		}
		if currentSum > maxSum {
			maxSum = currentSum
		}
	}
	return maxSum
}
