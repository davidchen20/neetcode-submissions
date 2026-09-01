class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);

        return dp(memo, coins, amount);
    }

    // returns the number of coins needed to make the amount
    int dp(vector<int>& memo, vector<int>& coins, int remaining) {
        if (remaining == 0) return 0;
        if (remaining < 0) return -1;

        // for (int count = 0; count < coins.size(); count++) {
        //     if (remaining == coins[count]) return 1;
        // }

        if (memo[remaining] != -2) return memo[remaining];

        int minCost = INT_MAX;
        for (int count = 0; count < coins.size(); count++) {
            int remainingCount = dp(memo, coins, remaining - coins[count]);

            if (remainingCount == -1) continue;

            minCost = min(minCost, 1 + remainingCount);
        }

        if (minCost == INT_MAX) minCost = -1;

        memo[remaining] = minCost;
        return memo[remaining];
    }
};
