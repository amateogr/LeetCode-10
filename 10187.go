package leetcode

func findRepeatedDnaSequences(s string) []string {
	if len(s) < 10 {
		return nil
	}
	var m [128]uint8
	m['A'] = 0
	m['C'] = 1
	m['G'] = 2
	m['T'] = 3

	seen := make(map[int]bool, len(s)-9)
	added := make(map[int]bool)
	var res []string

	key := 0
	for i := 0; i < 10; i++ {
		key = (key << 2) | int(m[s[i]])
	}
	seen[key] = true

	mask := 0xFFFFF
	for i := 10; i < len(s); i++ {
		key = ((key << 2) & mask) | int(m[s[i]])
		if added[key] {
			continue
		}
		if seen[key] {
			res = append(res, s[i-9:i+1])
			added[key] = true
		} else {
			seen[key] = true
		}
	}
	return res
}
