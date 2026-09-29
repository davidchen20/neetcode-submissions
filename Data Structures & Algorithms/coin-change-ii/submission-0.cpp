class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // memo[i] = number of ways to make amount i from the given coins

        // memo[i] = memo[i - coins[k]]

        vector<int> memo(amount + 1);
        memo[0] = 1;

        for (auto coin : coins) {
            for (int i = 1; i < amount + 1; i++) {
                if (i - coin >= 0) {
                    memo[i] += memo[i-coin];
                }
            }
        }

        return memo[amount];
    }
};
