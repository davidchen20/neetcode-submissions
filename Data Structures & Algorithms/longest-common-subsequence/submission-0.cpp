class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 1 1 1 1 1
        // 1 1 2 2 2
        // 1 1 2 2 3

        // memo[i][j] = the longest common subsequence from text1[:i] and text2[:j]

        // if (text1[i] == text2[j]) memo[i][j] = 1 + memo[i-1][j-1]
        // else memo[i][j] = max(memo[i-1][j], memo[i][j-1])

        vector<vector<int>> memo(text1.size(), vector<int>(text2.size()));

        memo[0][0] = text1[0] == text2[0] ? 1 : 0;

        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (i == 0 && j == 0) continue;

                if (text1[i] == text2[j]) {
                    int topLeft = (i-1) >= 0 && (j-1) >= 0 ? memo[i-1][j-1] : 0;
                    memo[i][j] = 1 + topLeft;
                } else {
                    int left = j - 1 >= 0 ? memo[i][j-1] : 0;
                    int top = i - 1 >= 0 ? memo[i-1][j] : 0;
                    memo[i][j] = max(left, top);
                }
            }
        }

        return memo[text1.size() - 1][text2.size() - 1];
    }
};
