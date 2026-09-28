class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // memo[i] = min(memo[i-1] + cost[i], memo[i-2] + cost[i-2])
        int n = cost.size() + 1;
        vector<int> memo(n);
        memo[0] = 0;
        memo[1] = 0;

        for (int i = 2; i < n; i++) {
            memo[i] = min(memo[i-1] + cost[i-1], memo[i-2] + cost[i-2]);
        }

        return memo[n-1];
    }
};
