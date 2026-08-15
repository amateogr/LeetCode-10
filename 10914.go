package leetcode

func hasGroupsSizeX(deck []int) bool {
	var freq [10000]int
	for i := 0; i < len(deck); i++ {
		freq[deck[i]]++
	}

	g := 0
	for i := 0; i < 10000; i++ {
		if freq[i] > 0 {
			g = gcd(g, freq[i])
			if g == 1 {
				return false
			}
		}
	}
	return g >= 2
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
