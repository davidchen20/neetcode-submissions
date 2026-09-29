class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n));

        // memo[i][j] = the number of unique paths to get to (i,j)

        // memo[i][j] = memo[i-1][j] + memo[i][j-1]

        memo[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int leftAmount = j - 1 >= 0 ? memo[i][j-1] : 0;
                int topAmount = i - 1 >= 0 ? memo[i-1][j] : 0;

                memo[i][j] = topAmount + leftAmount;
            }
        }

        return memo[m-1][n-1];
    }
};
