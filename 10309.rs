impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut hold = i32::MIN;
        let mut sold = 0;
        let mut rest = 0;
        for price in prices {
            let prev_sold = sold;
            sold = hold + price;
            hold = hold.max(rest - price);
            rest = rest.max(prev_sold);
        }
        sold.max(rest)
    }
}