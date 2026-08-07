import (
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
	s := make([]string, len(nums))
	for i, v := range nums {
		s[i] = strconv.Itoa(v)
	}

	sort.Slice(s, func(i, j int) bool {
		return s[i]+s[j] > s[j]+s[i]
	})

	if s[0] == "0" {
		return "0"
	}

	var sb strings.Builder
	for _, v := range s {
		sb.WriteString(v)
	}
	return sb.String()
}