class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size()));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) memo[i][j] = true;
                else if (j - i == 1) memo[i][j] = s[i] == s[j];
                else memo[i][j] = s[i] == s[j] && memo[i+1][j-1];
            }
        }

        vector<vector<string>> ans;
        vector<string> part;
        dfs(ans, memo, part, s, 0);

        return ans;
    }

    void dfs(vector<vector<string>>& ans, vector<vector<bool>>& memo, vector<string>& part, string& s, int i) {
        if (i >= s.size()) {
            ans.push_back(part);
        } else {
            for (int j = i; j < s.size(); j++) {
                if (memo[i][j]) {
                    part.push_back(s.substr(i, j - i + 1));
                    dfs(ans, memo, part, s, j + 1);
                    part.pop_back();
                }
            }
        }
    }
};
