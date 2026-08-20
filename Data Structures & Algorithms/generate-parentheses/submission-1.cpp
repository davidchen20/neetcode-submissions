class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
    
        dfs(ans, path, 0, 0, n);

        return ans;
    }

    void dfs(vector<string>& ans, string& path, int closed, int opened, int n) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        } else {
            if (opened < n) {
                path.push_back('(');
                dfs(ans, path, closed, opened + 1, n);
                path.pop_back();
            }

            if (closed < opened) {
                path.push_back(')');
                dfs(ans, path, closed + 1, opened, n);
                path.pop_back();
            }
        }
    }
};
