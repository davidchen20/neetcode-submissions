class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        
        return min(dp(cost, memo, 0), dp(cost, memo, 1));
    }

    int dp(vector<int>& cost, vector<int>& memo, int i) {
        if (i >= cost.size()) return 0;
        if (memo[i] != -1) return memo[i];

        memo[i] = cost[i] + min(dp(cost, memo, i + 1), dp(cost, memo, i + 2));

        return memo[i];
    }
};
