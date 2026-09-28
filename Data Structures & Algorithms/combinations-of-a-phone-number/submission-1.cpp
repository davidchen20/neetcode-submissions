class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string>();
        vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;

        string path;

        dfs(m, digits, ans, path, 0);

        return ans;
    }

    void dfs(vector<string>& m, string& digits, vector<string>& ans, string& path, int i) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
        } else {
            char digit = digits[i];
            string& possible = m[digit - '0' - 2];

            for (int j = 0; j < possible.size(); j++) {
                path.push_back(possible[j]);
                dfs(m, digits, ans, path, i + 1);
                path.pop_back();
            }
        }
    } 
};
