class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> memo(n);
        memo[0] = 1;
        memo[1] = 2;

        return dp(memo, n-1);
    }

    int dp(vector<int>& memo, int n) {
        if (memo[n] > 0) return memo[n];

        memo[n] = dp(memo, n-1) + dp(memo, n-2);

        return memo[n];
    }
};
