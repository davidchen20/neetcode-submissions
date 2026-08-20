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
                path += "(";
                dfs(ans, path, closed, opened + 1, n);
                path = path.substr(0, path.size() - 1);
            }

            if (closed < opened) {
                path += ")";
                dfs(ans, path, closed + 1, opened, n);
                path = path.substr(0, path.size() - 1);
            }
        }
    }
};
