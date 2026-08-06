impl Solution {
    pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
        for row in (0..triangle.len() - 1).rev() {
            for i in 0..=row {
                triangle[row][i] += std::cmp::min(triangle[row + 1][i], triangle[row + 1][i + 1]);
            }
        }
        triangle[0][0]
    }
}