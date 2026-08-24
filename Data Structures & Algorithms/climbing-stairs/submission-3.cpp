class Solution {
public:
    int climbStairs(int n) {
        return dp(n-1);
    }

    int dp(int n) {
        vector<int> memo(45);
        memo[0] = 1;
        memo[1] = 2;

        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n];
    }
};
