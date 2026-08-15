func kthSmallest(matrix [][]int, k int) int {
    n := len(matrix)
    low := matrix[0][0]
    high := matrix[n-1][n-1]
    ans := low
    for low <= high {
        mid := low + (high-low)/2
        if countLessOrEqual(matrix, n, mid) >= k {
            ans = mid
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    return ans
}

func countLessOrEqual(matrix [][]int, n int, mid int) int {
    count := 0
    row := n - 1
    col := 0
    for row >= 0 && col < n {
        if matrix[row][col] <= mid {
            count += row + 1
            col++
        } else {
            row--
        }
    }
    return count
}