impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let n = num_rows as usize;
        let mut result = Vec::with_capacity(n);
        if n == 0 {
            return result;
        }

        result.push(vec![1]);
        for i in 1..n {
            let prev = &result[i - 1];
            let mut row = Vec::with_capacity(i + 1);
            row.push(1);
            for j in 0..prev.len() - 1 {
                row.push(prev[j] + prev[j + 1]);
            }
            row.push(1);
            result.push(row);
        }
        result
    }
}