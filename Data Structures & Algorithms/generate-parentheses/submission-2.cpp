class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;

        dfs(ans, path, n, n);
        return ans;
    }

    void dfs(vector<string>& ans, string& path, int opens, int ends) {
        if (opens == 0 && ends == 0) {
            ans.push_back(path);
            return;
        }

        if (opens > 0) {
            path.push_back('(');
            dfs(ans, path, opens-1, ends);
            path.pop_back();
        }

        if (opens < ends && ends > 0) {
            path.push_back(')');
            dfs(ans, path, opens, ends - 1);
            path.pop_back();
        }
    }
};
