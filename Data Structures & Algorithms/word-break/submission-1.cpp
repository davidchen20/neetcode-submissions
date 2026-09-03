class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return dfs(memo, wordDict, s, 0);
    }

    bool dfs(vector<int>& memo, vector<string>& wordDict, string& s, int i) {
        // base case
        if (i == s.size()) return 1;

        // memo check
        if (memo[i] != -1) return memo[i];
        // memo set
        for (string& word : wordDict) {
            // if it is in the remaining stirng
            if (i + word.size() <= s.size() && s.substr(i, word.size()) == word && dfs(memo, wordDict, s, i + word.size())) {
                memo[i] = 1;
                return memo[i];
            }
        }

        memo[i] = 0;

        // return
        return memo[i];
    }
};
