impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let n = t.len();
        let mut dp = vec![0; n + 1];
        dp[0] = 1;
        for &sc in s {
            for j in (1..=n).rev() {
                if sc == t[j - 1] {
                    dp[j] += dp[j - 1];
                }
            }
        }
        dp[n]
    }
}