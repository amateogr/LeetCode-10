package leetcode

import "strconv"

func calPoints(ops []string) int {
	scores := make([]int, 0, len(ops))
	sum := 0
	for _, op := range ops {
		switch op {
		case "+":
			val := scores[len(scores)-1] + scores[len(scores)-2]
			scores = append(scores, val)
			sum += val
		case "D":
			val := scores[len(scores)-1] * 2
			scores = append(scores, val)
			sum += val
		case "C":
			sum -= scores[len(scores)-1]
			scores = scores[:len(scores)-1]
		default:
			val, _ := strconv.Atoi(op)
			scores = append(scores, val)
			sum += val
		}
	}
	return sum
}
