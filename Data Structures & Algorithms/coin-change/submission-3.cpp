class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // memo[i] = minimum # of coins required to get i dollars
        // memo[i] = min(memo[j] + memo[i - j]);
        vector<int> memo(amount + 1, INT_MAX);

        memo[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c = 0; c < coins.size(); c++) {
                if (i - coins[c] >= 0 && memo[i - coins[c]] != INT_MAX) {
                    memo[i] = min(memo[i], 1 + memo[i - coins[c]]);
                }
            }
        }

        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};
