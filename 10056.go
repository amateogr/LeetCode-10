package leetcode

import "sort"

func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var merged [][]int
	for _, interval := range intervals {
		if len(merged) == 0 || merged[len(merged)-1][1] < interval[0] {
			merged = append(merged, interval)
		} else {
			if interval[1] > merged[len(merged)-1][1] {
				merged[len(merged)-1][1] = interval[1]
			}
		}
	}

	return merged
}
