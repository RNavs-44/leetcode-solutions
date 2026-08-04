class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_preceding_price = prices[0]; 
        int profit = 0;
        for (int r = 1; r < prices.size(); r++) {
            profit = max(prices[r] - lowest_preceding_price, profit);
            lowest_preceding_price = min(lowest_preceding_price, prices[r]);
        }
        return profit;
    }
};
