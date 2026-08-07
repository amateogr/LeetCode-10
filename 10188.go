package leetcode

func maxProfit(k int, prices []int) int {
	n := len(prices)
	if n <= 1 || k == 0 {
		return 0
	}
	if k >= n/2 {
		ans := 0
		for i := 1; i < n; i++ {
			if prices[i] > prices[i-1] {
				ans += prices[i] - prices[i-1]
			}
		}
		return ans
	}
	buy := make([]int, k+1)
	sell := make([]int, k+1)
	for i := range buy {
		buy[i] = -prices[0]
	}
	for _, price := range prices {
		for j := 1; j <= k; j++ {
			if sell[j-1]-price > buy[j] {
				buy[j] = sell[j-1] - price
			}
			if buy[j]+price > sell[j] {
				sell[j] = buy[j] + price
			}
		}
	}
	return sell[k]
}
