impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let n = row_index as i64;
        let mut row = vec![1; (row_index + 1) as usize];
        let mut prev = 1;
        for i in 1..=(row_index as usize / 2) {
            prev = prev * (n - i as i64 + 1) / i as i64;
            row[i] = prev as i32;
            row[row_index as usize - i] = prev as i32;
        }
        row
    }
}