impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let mut arr = Vec::with_capacity(nums.len() + 2);
        arr.push(1);
        arr.extend(nums);
        arr.push(1);
        let n = arr.len();
        let mut dp = vec![vec![0; n]; n];

        for len in 3..=n {
            for i in 0..=n - len {
                let j = i + len - 1;
                for k in i + 1..j {
                    dp[i][j] = dp[i][j].max(dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);
                }
            }
        }
        dp[0][n - 1]
    }
}