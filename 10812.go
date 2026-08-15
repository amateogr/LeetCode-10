package leetcode

func largestTriangleArea(points [][]int) float64 {
	var maxArea float64
	n := len(points)
	for i := 0; i < n-2; i++ {
		p1 := points[i]
		x1, y1 := float64(p1[0]), float64(p1[1])
		for j := i + 1; j < n-1; j++ {
			p2 := points[j]
			x2, y2 := float64(p2[0]), float64(p2[1])
			for k := j + 1; k < n; k++ {
				p3 := points[k]
				x3, y3 := float64(p3[0]), float64(p3[1])
				area := 0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))
				if area < 0 {
					area = -area
				}
				if area > maxArea {
					maxArea = area
				}
			}
		}
	}
	return maxArea
}
