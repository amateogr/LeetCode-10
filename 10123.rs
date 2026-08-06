impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut t1_cost, mut t1_profit, mut t2_cost, mut t2_profit) = (i32::MAX, 0, i32::MAX, 0);
        for price in prices {
            t1_cost = t1_cost.min(price);
            t1_profit = t1_profit.max(price - t1_cost);
            t2_cost = t2_cost.min(price - t1_profit);
            t2_profit = t2_profit.max(price - t2_cost);
        }
        t2_profit
    }
}