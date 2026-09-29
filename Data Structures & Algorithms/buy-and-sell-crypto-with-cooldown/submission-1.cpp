class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // no stock: skipped (no stock), sold (with stock)
        // have stock: skipped (with stock), bought (with no stock)

        // memo[i][0] = max profit you could make if you didn't have stock
        // memo[i][1] = max profit you could make if you have stock

        // memo[i][0] = max(memo[i-1][0], memo[i-1][1] + prices[i])
        // memo[i][1] = max(memo[i-1][1], memo[i-2][1] - prices[i])

        // 0 2 3 3 3
        // 0 0 1 1 1
        // 0 0 0 0 0
        // 0 0 0 0 4
        // 0 0 0 0 0

        vector<vector<int>> memo(prices.size(), vector<int>(2));

        memo[0][0] = 0;
        memo[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            memo[i][0] = max(memo[i-1][0], memo[i-1][1] + prices[i]);
            
            int buying = i - 2 >= 0 ? memo[i-2][0] - prices[i] : -prices[i];
            memo[i][1] = max(memo[i-1][1], buying);
        }

        return memo[prices.size() - 1][0];
    }
};
