class Solution {
public:    
    int minCostClimbingStairs(vector<int>& cost) {
        return dp(cost);
    }

    int dp(vector<int>& cost) {
        vector<int> memo(cost.size() + 1);
        memo[0] = 0;
        memo[1] = 0;

        for (int i = 2; i < memo.size(); i++) {
            memo[i] = min(memo[i-1] + cost[i-1], memo[i-2] + cost[i-2]);
        }

        return memo[cost.size()];
    }
};