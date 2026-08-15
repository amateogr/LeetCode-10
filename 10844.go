package leetcode

func backspaceCompare(s string, t string) bool {
	i, j := len(s)-1, len(t)-1
	skipS, skipT := 0, 0

	for i >= 0 || j >= 0 {
		for i >= 0 {
			if s[i] == '#' {
				skipS++
				i--
			} else if skipS > 0 {
				skipS--
				i--
			} else {
				break
			}
		}

		for j >= 0 {
			if t[j] == '#' {
				skipT++
				j--
			} else if skipT > 0 {
				skipT--
				j--
			} else {
				break
			}
		}

		if i >= 0 && j >= 0 && s[i] != t[j] {
			return false
		}

		if (i >= 0) != (j >= 0) {
			return false
		}

		i--
		j--
	}

	return true
}
